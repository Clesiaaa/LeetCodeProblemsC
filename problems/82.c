struct ListNode* deleteDuplicates(struct ListNode* h){
    if(!h || !h->next) return h;
    if(h->val == h->next->val){
        while(h->next && h->val == h->next->val) h = h->next;
        return deleteDuplicates(h->next);
    }
    return h->next = deleteDuplicates(h->next), h;
}