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
  PackAnimal animal;
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
  new_node->animal = animal;
  new_node->next = caravan->head;
  caravan->head = new_node;
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  if(caravan->head==0||animal==0)
  return;
  if(caravan->head->animal == animal)
  {
    Node* toBeDeleted=caravan->head;
    caravan->head=caravan->head->next;
    sfree(toBeDeleted);
  }
  else{
    Node* currNode=caravan->head;
    while(currNode->next != 0 && currNode->next->animal != animal){
      currNode = currNode->next;
    }

  if(currNode->next != 0){
    Node* toBeDeleted=currNode->next;
    currNode->next=currNode->next->next;
    sfree(toBeDeleted);
    }
  }
  add_to_caravan(animal,0);

}

int get_caravan_load(Caravan caravan)
{
  int load=0;

  Node* curr_node=caravan->head;
  while(curr_node!=0){
    load+=get_load((PackAnimal)curr_node->animal);
    curr_node=curr_node->next;
  }
  return load;
}

void unload(Caravan caravan)
{
  Node* curr_node = caravan->head;
  while(curr_node != 0){
    unload(curr_node->animal);
    curr_node = curr_node->next;
  }
}

int get_caravan_speed(Caravan caravan)
{
  if(caravan->head!=0){
  Node* curr_node=caravan->head;
  int min_speed=get_actual_speed((PackAnimal)curr_node->animal);
  while(curr_node!=0){
    if(min_speed>get_actual_speed((PackAnimal)curr_node->animal))
    {
      min_speed=get_actual_speed((PackAnimal)curr_node->animal);
    }
    curr_node=curr_node->next;
}
return min_speed;
}
return 0;
}
