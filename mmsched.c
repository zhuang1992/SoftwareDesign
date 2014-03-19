#include <linux/sched.h>
#include <linux/kernel.h>
#include <head.h>
#include <linux/mm.h>
struct mmNode{
        long addr;
        struct mmNode* next;
        struct mmNode(){
                next = NULL;
        }
}*head;
void swap_out(){
    long to_swap_out = get_tail();
    
}
//LRU
void update_queue(long addr){
        if(head->addr == addr)return;
        if(head == NULL){
                head = (struct mmNode*)malloc(sizeof(mmNode));
                head->addr = addr;
                head->next = NULL;
                return;
        }
        struct mmNode* ptr = head;
        struct mmNode* temp = NULL;
        while(!ptr->next){
                if(ptr->next->addr == addr){
                        temp = ptr->next;
                        ptr->next = ptr->next->next;
                        temp->next = head;
                        head = temp;
                        return; 
                }  
                ptr = ptr->next;      
        }
        struct mmNode new_head = (struct mmNode*)malloc(sizeof(mmNode));
        new_head->addr = addr;
        new_head->next = head;
        head = new_head;
        return;
}
long get_tail(){
        struct mmNode* ptr = head;
        while(!ptr->next){
                ptr = ptr->next;
        }
        return ptr->addr;
}
