#include "ex1.h"

// create a linked list to store info about block
typedef struct info_block
{
    int size;    // size of block
    int is_free; // is_free = 1 if that block is free, else = 0
    struct info_block *next;
} info_block;

static info_block *head, *tail;

void *allocate_aligned_block(unsigned int size, unsigned int align)
{
    void *p_cur, *p_block, *p_info_block;
    int addr_cur, offset;

    // allocate block for info block
    if (sbrk(sizeof(info_block)) == (void *)-1)
        return NULL;

    p_cur = sbrk(0);
    addr_cur = (uintptr_t)p_cur;

    // caculate the offset
    offset = addr_cur % align;
    if (offset > 0)
        offset = align - offset;
    
    // increase offset
    if (sbrk(offset) == (void *)-1)
        return NULL;

    // get pointer to block
    p_block = sbrk(0);

    // increase block size
    if (sbrk(size) == (void *)-1)
        return NULL;

    // info block is behind block
    p_info_block = p_block - sizeof(info_block);

    return p_info_block;
}

void *aligned_malloc(unsigned int size, unsigned int align)
{
    if (size == 0)
        return NULL;
    void *return_block;
    info_block *info = NULL;
    void *new_block;

    /* 
    The idea of my aligned_malloc() is that:
    Check the info_block linked list
        Case 1: if we can find one block which is free and has enough size
            No need to allocate new one, just reuse that block
        Case 2: if not,
            Allocate new aligned block by using allocate_aligned_block()
    */

    // Case 1:
    info_block *cur = head;
    while (cur)
    {
        if (cur->is_free && cur->size >= size)
        {
            info = cur;
            break;
        }
        cur = cur->next;
    }

    // found free block having enough size in the linked list
    if (info)
    {
        // now this block isn't free anymore, set it's variable is_free = 0
        info->is_free = 0;  
        return_block = (void *)(info + 1);
        printf("Old block: Info at %lu - Block at %lu\n", (uintptr_t)info, (uintptr_t)return_block);
        return return_block;
    }

    // Case 2:
    new_block = allocate_aligned_block(size, align);

    if (new_block == NULL)
        return NULL; // cannot allocate new block

    // store info block
    info = new_block;
    info->size = size;
    info->is_free = 0;
    info->next = NULL;

    // Update *head and *tail of the info_block linked list
    if (!head)
        head = info;
    if (tail)
        tail->next = info;
    tail = info;

    // Return new block
    return_block = (void *)(info + 1);
    printf("New block: Info at %lu - Block at %lu\n", (uintptr_t)info, (uintptr_t)return_block);
    return return_block;
}

void * aligned_free(void *ptr)
{

    info_block *info;
    info_block *tmp;
    void *program_break;

    if (!ptr) return NULL;

    // retrive block info and get the current program break
    info = (info_block *)ptr - 1;
    program_break = sbrk(0);

    /*
    The idea of my aligned_free is that:
    Check the position of the block we need to free in the linked list
        Case 1: if it is the *tail, we remove it from linked list
            Then we need to update *tail and program break;
        Case 2: if not, we still keep it in the linked list
            Then we set the variable is_free = 1 to reuse in the next aligned_malloc()
    */
    
    // Case 1:
    if (ptr + info->size == program_break)
    {
        if (head == tail) // linked list has only 1 block
            head = tail = NULL;
        else
        {
            tmp = head;
            // find the block point to last block
            while (tmp)
            {
                if (tmp->next == tail)
                {
                    tmp->next = NULL;
                    tail = tmp;
                }
                tmp = tmp->next;
            }
        }
        // release memory of last block to OS
        sbrk(0 - sizeof(info_block) - info->size);
        printf("Release memory to OS\n");
        return sbrk(0);
    }

    // Case 2:
    info->is_free = 1;
    return sbrk(0);
}
