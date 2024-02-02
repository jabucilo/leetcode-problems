#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};


struct ListNode *newNode(int val)
{
    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = 0;
    return new_node;
}

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *curr, *other, *prev, *ret, *temp;
    if (list1 == 0)
    {
        return list2;
    }
    else if (list2 == 0)
    {
        return list1;
    }

    if (list1->val <= list2->val)
    {
        curr = list1;
        other = list2;
        ret = list1;
    } else
    {
        curr = list2;
        other = list1;
        ret = list2;
    }

    while (curr && other)
    {
        while (curr && curr->val <= other->val)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = other;

        temp = curr;
        curr = other;
        other = temp;
    }
    return ret;
}


int main(void)
{
    struct ListNode *list1 = newNode(1);
    struct ListNode *l1 = list1;
    struct ListNode *list2 = newNode(2);
    struct ListNode *l2 = list2;

    for (int i = 2; i < 5; i++)
    {
        l1->next = newNode(1);
        l1 = l1->next;
        l2->next = newNode(5);
        l2 = l2->next;
    }
    struct ListNode *merged = mergeTwoLists(list1, list2);
    struct ListNode *prev;
    while (merged)
    {
        printf("%d\n", merged->val);
        prev = merged;
        merged = merged->next;
        free(prev);
    }
    return 0;
}
