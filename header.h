#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct st{
    int roll_no;
    char name[50];
    float percentage;
    struct st *next;
}SLL;

void add_new_record(SLL **);
void delete_a_record(SLL **);
int del_roll(SLL **);
int del_name(SLL **);
void show_list(SLL *);
void std_mod(SLL **);
void search_roll(SLL *);
void search_name(SLL *);
void search_percentage(SLL *);
void save(SLL *);
void save_exit(SLL *);
void sort_list(SLL *);
//void sort_roll(SLL *,int);
void delete_all(SLL **);
void reverse_link(SLL **);
