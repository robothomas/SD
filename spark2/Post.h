#include <Post.h>

class Post {
    int id;
    Post(int id_num; int communityID; string title);
    Post(int id_num; int communityID; string title; string description);
    Post(int id_num; int communityIDs[]; string title);
    Post(int id_num; int communityIDs[]; string title; string description);

    void display();
};