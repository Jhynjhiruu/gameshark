#include "common.h"

typedef struct chunk_s {
    char name[4];
    struct chunk_s *next;
    struct chunk_s *prev;
    int size;
} chunk_t;

chunk_t *HeapStart;
chunk_t *HeapEnd;

static void *fill(void *str, int c, size_t n) {
    u8 *ptr = str;
    size_t count = 0;

    while (count < n) {
        *ptr = c;
        count++;
        ptr++;
    };

    return str;
}

static chunk_t *getFirst(void) {
    return HeapStart;
}

static chunk_t *getNext(chunk_t *chunk) {
    return chunk->next;
}

static chunk_t *getPrev(chunk_t *chunk) {
    return chunk->prev;
}

static chunk_t *getLast(chunk_t *cur) {
    while (getNext(cur) != NULL) {
        cur = getNext(cur);
    }
    return cur;
}

static int getSpaceToNext(chunk_t *chunk) {
    return (int)chunk->next - ((int)chunk + sizeof(chunk_t));
}

void func_80042100(void *start, void *end) {
    chunk_t *cur;
    chunk_t *temp;

    HeapStart = start;
    HeapEnd = end;

    cur = getFirst();

    cur->name[0] = 'D';
    cur->name[1] = 'M';
    cur->name[2] = 'F';
    cur->next = HeapEnd - 1;
    cur->prev = NULL;

    temp = cur;
    cur = cur->next;

    cur->name[0] = 'D';
    cur->name[1] = 'M';
    cur->name[2] = 'T';
    cur->next = NULL;
    cur->prev = temp;
}

void *func_80042178(int len) { // malloc
    chunk_t *first;
    chunk_t *next_free;
    chunk_t *temp;
    void *buffer;

    ALIGN(len, 0x10);

    first = getFirst();
    while (((first->name[2] != 'F') || (getSpaceToNext(first) < len))) {
        first = getNext(first);
        if (first == NULL) {
            return (void *)(-1);
        }
    }

    buffer = (u8 *)first + sizeof(chunk_t); // space after the first free chunk

    first->name[2] = 'R'; // mark chunk as in use

    next_free = (chunk_t *)(((u8 *)first) + (sizeof(chunk_t)) + len);
    temp = first->next;
    first->next = next_free;
    first->next->prev = first;

    next_free->next = temp;
    next_free->name[0] = 'D';
    next_free->name[1] = 'M';
    next_free->name[2] = 'F';
    first = next_free->next;
    first->prev = next_free;

    fill(buffer, 0, len);
    return buffer;
}

int func_8004224C(void *ptr) { // free
    chunk_t *chunk_after;
    chunk_t *temp;
    chunk_t *chunk;

    chunk = ptr;
    chunk -= 1;

    if (chunk->name[0] != 'D') {
        return -1;
    }
    if (chunk->name[1] != 'M') {
        return -1;
    }
    if (chunk->name[2] != 'R') {
        return -1;
    }

    chunk->name[2] = 'F'; // mark chunk as free

    chunk_after = ((chunk_t *)ptr - 1)->next;
    temp = chunk_after->next;
    chunk_after->name[0] = '~';
    chunk_after->name[1] = '~';
    chunk_after->name[2] = '~';
    ((chunk_t *)ptr - 1)->next = temp;
    temp->prev = chunk;
    return 0;
}
