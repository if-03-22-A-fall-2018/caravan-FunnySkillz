/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "general.h"
#include "caravan.h"
#include <stdlib.h>

typedef struct _node{
  PackAnimal pack_animal;
  struct _node* next;
}Node;

struct CaravanImplementation{
  Node* head;
};

Caravan new_caravan()
{
  Caravan caravan = (Caravan)malloc(sizeof(struct CaravanImplementation));
  caravan->head = 0;
  return caravan;
}

int get_length(Caravan caravan)
{
  int count = 0;
  Node* curr_node = caravan->head;
  while(curr_node != 0){
    count++;
    curr_node = curr_node->next;
  }
  return count;
}

void delete_caravan(Caravan caravan)
{
  Node* curr_node = caravan->head;

  while (curr_node != 0) {
    Node* to_be_deleted = curr_node;
    curr_node = curr_node->next;
    sfree(to_be_deleted);
  }
  sfree(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->pack_animal = animal;
  new_node->next = caravan->head;
  caravan->head = new_node;
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  
}

int get_caravan_load(Caravan caravan)
{
  return 0;
}

void unload(Caravan caravan)
{
  Node* curr_node = caravan->head;
  while(curr_node != 0){
    unload(curr_node->pack_animal);
    curr_node = curr_node->next;
  }
}

int get_caravan_speed(Caravan caravan)
{
  return 0;
}

void optimize_load(Caravan caravan)
{

}
