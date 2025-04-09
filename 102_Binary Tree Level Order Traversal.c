/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 #define QUEUE_NUM (2000)
 struct queue {
     struct TreeNode *body[QUEUE_NUM];
     int head;
     int tail;
     int num;
 };
 
 static void queue_init(struct queue *q){
     q->head = 0;
     q->tail= 0;
     q->num= 0;
 }
 
 static void queue_enqueue(struct queue *q, struct TreeNode *node){
     if(q->num == QUEUE_NUM){
         return;
     }
 
     q->body[q->head++] = node;
     if(q->head == QUEUE_NUM){
         q->head = 0;
     }
     q->num++;
 }
 
 static struct TreeNode *queue_dequeue(struct queue *q){
     if(q->num == 0){
         return NULL;
     }
 
     struct TreeNode *ret = q->body[q->tail++];
     if(q->tail == QUEUE_NUM){
         q->tail = 0;
     }
     q->num--;
 
     return ret;
 }
 
 int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
 
     if(!root){
         *returnSize = 0;
         returnColumnSizes = malloc(0);
         return malloc(0);
     }
 
 
     // Create queue
     //current_queue & next_queue
     struct queue cur_q;
     queue_init(&cur_q);
     struct queue next_q;
     queue_init(&next_q);
     
     // enqueue root
     queue_enqueue(&cur_q, root);
 
     *returnSize = 0;
     int **ret = malloc(sizeof(int*) * (*returnSize));
     //ret[0] = malloc(sizeof(int));
     //ret[0][0] = root->val;
     *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
     //(*returnColumnSizes)[(*returnSize)-1] = 1;
 
     while (cur_q.num > 0){
         int *column_array = malloc(0);
         int array_num = 0;
         while (cur_q.num > 0){
             //dequeue
             struct TreeNode *node = queue_dequeue(&cur_q);
 
             // add value to current level array
             array_num++;
             column_array = realloc(column_array, sizeof(int)*array_num); 
             column_array[array_num-1] = node->val;
 
             //enqueue left node
             if(node->left){
                 queue_enqueue(&next_q, node->left);
             }
             //enqueue right node
             if(node->right){
                 queue_enqueue(&next_q, node->right);
             }
         }
     
         (*returnSize)++;
         ret = realloc(ret, sizeof(int*) * (*returnSize));
         ret[(*returnSize)-1] = column_array;
         
         *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * (*returnSize));
         (*returnColumnSizes)[(*returnSize)-1] = array_num;
 
         memcpy(&cur_q, &next_q, sizeof(cur_q));
         queue_init(&next_q);
     }
 
     return ret;
 }
