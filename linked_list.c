#include<stdlib.h>
#include<stdio.h>
//--------> this define section need to be completed <--------//|

// define struct ll_data

/* this is an example for struct ll_data definition
 * struct ll_data
 * {
 *    int val;
 *    int qt;
 *    char str[20];
 * }
 */


//--------> end of the section <--------//|

struct linked_list
{
   struct ll_data        data;
   struct linked_list *  next;
};

//################################## min, max and browse section ##################################

// cmp_funct(d1,d2) return  : 0 when d1==d2, 1 when d1>d2 and -1 when d1<d2
// order equal to           : 1 for max and -1 for min
int max_min_ll (struct linked_list * ll, struct ll_data * buff, int (*cmp_funct)(struct ll_data, struct ll_data), int order)
{
   if (!ll)
      return 0;
   *buff=ll->data;
   while (ll=ll->next)
   {
      if(order==cmp_funct(ll->data,*buff))
         *buff=ll->data;
   }
   return 1;
}

void browse_ll(struct linked_list * ll, int (*funct)(struct linked_list *,int,void *),void * data)
{
   int i=0;
   while(ll)
   {
      if(!funct(ll,i,data))
        break;
      i++;
      ll=ll->next;
   }
}

//################################## set, get and find ##################################
int set_ll_last(struct ll_data data, struct linked_list * ll)
{
   if(!ll)
      return 0;
   while (ll->next)
   {
      ll=ll->next;
   }
   ll->data=data;
   return 1;
}

int set_ll_index(struct ll_data data, int index, struct linked_list * ll)
{
   while ((index > 0) && (ll))
   {
      ll=ll->next;
      index--;
   }
   if (!ll)
      return 0 ;
   ll->data=data;
   return 1;
}

int get_ll_last(struct ll_data *data, struct linked_list * ll)
{
   if(!ll)
      return 0;
   while (ll->next)
   {
      ll=ll->next;
   }
   *data=ll->data;
   return 1;
}

int get_ll_index(struct ll_data *data, int index, struct linked_list * ll)
{
   while ((index > 0) && (ll))
   {
      ll=ll->next;
      index--;
   }
   if (!ll)
      return 0 ;
   *data=ll->data;
   return 1;
}

// cmp_funct(d1,d2) return  : 0 when d1==d2, 1 when d1>d2 and -1 when d1<d2
int find_ll (struct ll_data data, struct linked_list * ll, int (*cmp_funct)(struct ll_data, struct ll_data))
{
   int i=0;
   while (ll)
   {
      if(!cmp_funct(ll->data,data))
         return i;
      i++;
      ll=ll->next;
   }
   return -1;
}

//################################## add section ##################################
static inline void add_ll(struct ll_data data, struct linked_list ** ll) //don't use it directly it has no treatment for abnormal scenarios
{
   struct linked_list * buff = (struct linked_list *)malloc(sizeof(struct linked_list));
   buff->next=*ll;
   buff->data=data;
   *ll=buff;
}

// cmp_funct(d1,d2) return  : 0 when d1==d2, 1 when d1>d2 and -1 when d1<d2
// order equal to           : 1 for bigger is first and -1 for smaller is first
void add_ll_sort (struct ll_data data, struct linked_list ** ll, int (*cmp_funct)(struct ll_data, struct ll_data), int order)
{
   if(!*ll)
   {
      (*ll)=(struct linked_list*)malloc(sizeof(struct linked_list));
      (*ll)->data=data;
      (*ll)->next=NULL;
   }
   else if(order !=cmp_funct((*ll)->data,data))
      add_ll(data,ll);
   else
      add_ll_sort(data,&((*ll)->next),cmp_funct,order);
}

void add_ll_first(struct ll_data data, struct linked_list ** ll)
{
   add_ll(data,ll);
}

void add_ll_last(struct ll_data data, struct linked_list ** ll)
{
   while(*ll)
   {
      ll=(&(*ll)->next);
   }
   add_ll(data,ll);
}

int add_ll_index (struct ll_data data, int index, struct linked_list ** ll)
{
   while ((index > 0) && (*ll))
   {
      ll=(&(*ll)->next);
      index--;
   }
   if(index > 0)
      return 0 ;
   return add_ll(data,ll), 1;
}

//################################## delete and free section ##################################
static inline void delete_ll(struct linked_list ** ll) //don't use it directly it has no treatment for abnormal scenarios
{
   struct linked_list * buff = (*ll)->next;
   free (*ll);
   *ll=buff;
}

int delete_ll_index (int index, struct linked_list ** ll)
{
   if(!*ll)
      return  0;
   if(0 >= index)
      return delete_ll(ll),1;
   return delete_ll_index(index-1,&((*ll)->next));
}

int delete_ll_first(struct linked_list ** ll)
{
   if(!*ll)
      return 0;
   return delete_ll(ll),1;
}

int delete_ll_last(struct linked_list ** ll)
{
   if(!*ll)
      return 0;
   if(!(*ll)->next)
      return delete_ll(ll),1;
   return delete_ll_last(&((*ll)->next));
}

// cmp_funct(d1,d2) return  : 0 when d1==d2, 1 when d1>d2 and -1 when d1<d2
int delete_ll_val(struct ll_data data, struct linked_list ** ll, int (*cmp_funct)(struct ll_data, struct ll_data))
{
   if(!*ll)
      return 0;
   if(!cmp_funct((*ll)->data,data))
      return delete_ll(ll), 1;
   return delete_ll_val(data,&((*ll)->next),cmp_funct);
}

void free_ll (struct linked_list ** nullified_buff)
{
   struct linked_list * ll =*nullified_buff;
   struct linked_list * buff;
   while(ll)
   {
      buff=ll;
      ll=ll->next;
      free(buff);
   }
   *nullified_buff=NULL;
}
