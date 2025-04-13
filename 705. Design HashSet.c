#define HASHSIZE (1000)
#define TRUE (1)
#define FALSE (0)

typedef struct _Bucket {
    int key;
    struct _Bucket *next;
} Bucket;

typedef struct {
    Bucket *buckets[HASHSIZE];
} MyHashSet;

MyHashSet* myHashSetCreate() {
    MyHashSet *obj = malloc(sizeof(MyHashSet));
    for(int i=0; i<HASHSIZE; i++){
        obj->buckets[i] = malloc(sizeof(Bucket));
        obj->buckets[i]->key = -1;
        obj->buckets[i]->next = NULL;
    }
    return obj;
}

int getIndex(int key){
    return (key % HASHSIZE);
}

void myHashSetAdd(MyHashSet* obj, int key) {
    if (key < 0){
        return;
    }
    if (obj == NULL){
        return;
    }

    int index = getIndex(key);
    Bucket *bucket = obj->buckets[index];

    if (bucket == NULL){
        bucket = malloc(sizeof(Bucket));
        bucket->key = key;
        bucket->next = NULL;
        return;
    }

    while(bucket){
        if (bucket->key == key) {
            // Already exits.
            return;
        }

        if (bucket->next == NULL){
            if(bucket->key < key){
                Bucket *tmp = malloc(sizeof(Bucket));
                tmp->key = key;
                tmp->next = NULL;
                bucket->next = tmp;
                break;
            } else {
                Bucket *tmp = malloc(sizeof(Bucket));
                tmp->key = key;
                tmp->next = bucket;
                break;
            }
        } else {
            if(bucket->key < key && key < bucket->next->key){
                Bucket *tmp = malloc(sizeof(Bucket));
                tmp->key = key;
                tmp->next = bucket->next;
                bucket->next = tmp;
                break;
            }
        }
        bucket = bucket->next;
    }

    return;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    if (key < 0){
        return;
    }
    if (obj == NULL){
        return;
    }

    int index = getIndex(key);
    Bucket *bucket = obj->buckets[index];
    if (bucket == NULL){
        return;
    }else if (bucket->key == key){
        Bucket *tmp = bucket;
        obj->buckets[index] = bucket->next;
        free(tmp);
        return;
    }

    while(bucket){
        if (bucket->next == NULL){
            break;
        } else {
            if(bucket->next->key == key){
                Bucket *tmp = bucket->next;
                bucket->next = tmp->next;
                free(tmp);
                break;
            }
        }
        bucket = bucket->next;
    }

    return;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    if (key < 0){
        return FALSE;
    }
    if (obj == NULL){
        return FALSE;
    }

    int index = getIndex(key);
    Bucket *bucket = obj->buckets[index];
    if (bucket == NULL){
        return FALSE;
    }

    while(bucket){
        if (bucket->key == key){
            return TRUE;
        }
        bucket = bucket->next;
    }

    return FALSE;
}

void myHashSetFree(MyHashSet* obj) {

    if (obj == NULL) {
        return;
    }

    for(int i=0; i<HASHSIZE; i++){
        Bucket *bucket = obj->buckets[i];
        while (bucket) {
            Bucket *tmp = bucket->next;
            free(bucket);
            bucket = tmp;
        }
    }
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);

 * myHashSetRemove(obj, key);

 * bool param_3 = myHashSetContains(obj, key);

 * myHashSetFree(obj);
*/
