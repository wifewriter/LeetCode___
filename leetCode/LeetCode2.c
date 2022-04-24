//
// Created by Administrator on 2020/3/2.
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int sum,flag=0;
    if(!l1->val&&!l1->next)return l2;
    if(!l2->val&&!l2->next)return l1;
    struct ListNode* head,*p,*temp;
    head=(struct ListNode*)malloc(sizeof(struct ListNode));
    head->next= NULL;
    head->val = 0;
    p=head;
    for(;l1&&l2;l1=l1->next,l2=l2->next){
        sum = l1->val+l2->val +flag;
        flag = 0;
        if(sum>9){
            flag=1;
            sum -= 10;
        }
        temp =(struct ListNode*)malloc(sizeof(struct ListNode));
        temp ->next = NULL;
        temp->val =sum;
        p->next=temp;
        p=temp;
    }if(!l1&&!l2){
        if(flag){
            temp =(struct ListNode*)malloc(sizeof(struct ListNode));
            temp ->next = NULL;
            temp->val =flag;
            p->next=temp;
        }
    }
    else if(!l1){
        while(flag){
            if(l2){
                sum = flag+l2->val;
                l2=l2->next;
                flag =0;
            }else {sum=flag;
                flag =0;
            };
            if(sum>9){
                flag =1;
                sum-=10;
            }
            temp =(struct ListNode*)malloc(sizeof(struct ListNode));
            temp ->next = NULL;
            temp->val =sum;
            p->next=temp;
            p=temp;
        }
        p->next = l2;
    }
    else if(!l2){
        while(flag){
            if(l1){
                sum = flag+l1->val;
                l1=l1->next;
                flag =0;
            }else{ sum = flag;
                flag =0;
            }
            if(sum>9){
                flag =1;
                sum-=10;
            }
            temp =(struct ListNode*)malloc(sizeof(struct ListNode));
            temp ->next = NULL;
            temp->val =sum;
            p->next=temp;
            p=temp;
        }
        p->next = l1;
    }
    p=head->next;
    free(head);
    return p;
}

