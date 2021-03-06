#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */
    if (!q)
        return NULL;
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* How about freeing the list elements and the strings? */
    /* Free queue structure */
    if (!q)
        return;
    list_ele_t *tmp = q->head;
    while (tmp) {
        q->head = q->head->next;
        free(tmp->value);
        free(tmp);
        tmp = q->head;
    }
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    free(q);
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    /* What should you do if the q is NULL? */
    if (!q)
        return false;

    list_ele_t *newh = NULL;
    newh = malloc(sizeof(list_ele_t));
    if (!newh)
        return false;
    /* Don't forget to allocate space for the string and copy it */
    /* What if either call to malloc returns NULL? */
    int len = strlen(s);
    newh->value = malloc(sizeof(char) * (len + 1));
    if (!newh->value) {
        free(newh);
        return false;
    }
    strncpy(newh->value, s, len + 1);
    if (!q->head) {
        q->tail = newh;
    }
    newh->next = q->head;
    q->head = newh;
    (q->size)++;
    return true;
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    /*  You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    if (!q)
        return false;
    list_ele_t *newh = NULL;
    newh = malloc(sizeof(list_ele_t));
    if (!newh)
        return false;
    int len = strlen(s);
    newh->value = malloc(len + 1);
    if (!newh->value) {
        free(newh);
        return false;
    }
    strncpy(newh->value, s, len + 1);
    newh->next = NULL;
    if (!q->head) {
        q->head = newh;
    } else {
        q->tail->next = newh;
    }
    q->tail = newh;
    (q->size)++;
    return true;
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /*  You need to fix up this code. */
    if (!q || !q->head)
        return false;
    list_ele_t *tmp = q->head;
    q->head = q->head->next;
    if (!q->head) {
        q->tail = NULL;
    }
    (q->size)--;
    if (tmp->value) {
        if (sp != NULL) {
            strncpy(sp, tmp->value, (bufsize - 1));
            sp[bufsize - 1] = '\0';
        }
        free(tmp->value);
    }
    free(tmp);
    return true;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* Remember: It should operate in O(1) time */
    if (!q)
        return 0;
    return q->size;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /*  You need to write the code for this function */
    if (!q || !q->head)
        return;
    list_ele_t *tmp = q->head;
    list_ele_t *prev_ele = q->head;
    list_ele_t *next_ele = q->head->next;
    while (next_ele != NULL) {
        tmp = next_ele;
        next_ele = tmp->next;
        tmp->next = prev_ele;
        prev_ele = tmp;
    }
    q->tail = q->head;
    q->head = tmp;
    q->tail->next = NULL;
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
