#include<iostream>
#include<cstring>

using namespace std;

// class combines the task_id & task_name 
class DoublyLinkedTaskNode {
private:
    int task_id;
    char *task_name;
    DoublyLinkedTaskNode *prev;
    DoublyLinkedTaskNode *next;
public:
    DoublyLinkedTaskNode(int, char *, int);

    int get_task_id();

    bool set_task_id(int);

    char *get_task_name();

    bool set_task_name(char *, int);

    bool set_next(DoublyLinkedTaskNode *);

    DoublyLinkedTaskNode *get_next();

    bool set_prev(DoublyLinkedTaskNode *);

    DoublyLinkedTaskNode *get_prev();
};

DoublyLinkedTaskNode::DoublyLinkedTaskNode(int id, char *name, int len) {
    task_id = id;
    task_name = new char[len];
    for (int i = 0; i < len; i++) {
        task_name[i] = name[i];
    }
    prev = NULL;
    next = NULL;
}

int DoublyLinkedTaskNode::get_task_id() {
    return task_id;
}

bool DoublyLinkedTaskNode::set_task_id(int id) {
    task_id = id;
    return true;
}

char *DoublyLinkedTaskNode::get_task_name() {
    return task_name;
}

bool DoublyLinkedTaskNode::set_task_name(char *name, int len) {
    if (task_name != NULL) {
        delete task_name;
    }

    task_name = new char[len];
    for (int i = 0; i < len; i++) {
        task_name[i] = name[i];
    }

    return true;
}

bool DoublyLinkedTaskNode::set_next(DoublyLinkedTaskNode *n) {
    next = n;
    return true;
}

bool DoublyLinkedTaskNode::set_prev(DoublyLinkedTaskNode *n) {
    prev = n;
    return true;
}

DoublyLinkedTaskNode *DoublyLinkedTaskNode::get_next() {
    return next;
}

DoublyLinkedTaskNode *DoublyLinkedTaskNode::get_prev() {
    return prev;
}

////////////////////////////////////////////////////////////////////////////////////

class DoublyLinkedTaskList {
private:
    DoublyLinkedTaskNode *begin;

public:
    DoublyLinkedTaskList();

    ~DoublyLinkedTaskList();

    bool add_task(int, char *, int);

    bool remove_all_task_id(int);

    bool does_task_exist(int task_id);

    char *get_task_name();

    int get_task_id();
};

int DoublyLinkedTaskList::get_task_id() {
    return begin->get_task_id();
}

char *DoublyLinkedTaskList::get_task_name() {
    return begin->get_task_name();
}

DoublyLinkedTaskList::DoublyLinkedTaskList() {
    begin = NULL;
}

bool DoublyLinkedTaskList::does_task_exist(int task_id) {
    DoublyLinkedTaskNode *curr = begin;
    while (curr != NULL) {
        if (curr->get_task_id() == task_id) {
            return true;
        }
        curr = curr->get_next();
    }
    return false;
}

bool DoublyLinkedTaskList::add_task(int id, char *name, int len) {
    DoublyLinkedTaskNode *temp = new DoublyLinkedTaskNode(id, name, len);
    if (temp == NULL) {
        return false;
    }

    if (begin == NULL) {
        begin = temp;
        return true;
    }

    DoublyLinkedTaskNode *curr = begin;
    while (curr->get_next() != NULL)
        curr = curr->get_next();

    curr->set_next(temp);
    temp->set_prev(curr);
    return true;
}

DoublyLinkedTaskList::~DoublyLinkedTaskList() {
    DoublyLinkedTaskNode *temp = begin;
    while (temp != NULL) {
        DoublyLinkedTaskNode *save = temp->get_next();
        delete temp;
        temp = save;
    }
}

bool DoublyLinkedTaskList::remove_all_task_id(int id) {
    DoublyLinkedTaskNode *curr = begin;
    while (curr != NULL) {
        DoublyLinkedTaskNode *next = curr->get_next();
        if (curr->get_task_id() == id) {
            DoublyLinkedTaskNode *prev = curr->get_prev();
            if (prev == NULL) {
                begin = next;
                begin->set_prev(NULL);
            }
            else {
                prev->set_next(next);
            }
            delete curr;
        }
        curr = next;
    }
    return true;
}

/////////////////////////////////////////////////////////////////////////////////

class PrioritizedTaskListNode {
private:
    int priority;
    DoublyLinkedTaskList tasks;
    PrioritizedTaskListNode *left;
    PrioritizedTaskListNode *right;

public:
    PrioritizedTaskListNode();

    PrioritizedTaskListNode(int p);

    bool add_task(int taskId, char *taskName, int length);

    bool set_priority(int p);

    int get_priority();

    DoublyLinkedTaskList get_task_list();

    bool set_left(PrioritizedTaskListNode *n);

    PrioritizedTaskListNode *get_left();

    bool set_right(PrioritizedTaskListNode *n);

    PrioritizedTaskListNode *get_right();

    bool remove_task_id(int);

    bool does_task_id_exist(int);
//    bool is_present(int);

    char *get_task_name();

    int get_task_id();
};

int PrioritizedTaskListNode::get_task_id() {
    return tasks.get_task_id();
}

char *PrioritizedTaskListNode::get_task_name() {
    return this->tasks.get_task_name();
}

bool PrioritizedTaskListNode::does_task_id_exist(int task_id) {
    return tasks.does_task_exist(task_id);
}

PrioritizedTaskListNode::PrioritizedTaskListNode() {
    priority = 0;
    left = right = NULL;
}

PrioritizedTaskListNode::PrioritizedTaskListNode(int p) {
    priority = p;
    left = right = NULL;
}

bool PrioritizedTaskListNode::add_task(int taskId, char *taskName, int length) {
    tasks.add_task(taskId, taskName, length);
    return true;
}

bool PrioritizedTaskListNode::set_priority(int p) {
    priority = p;
    return true;
}

int PrioritizedTaskListNode::get_priority() {
    return priority;
}

DoublyLinkedTaskList PrioritizedTaskListNode::get_task_list() {
    return tasks;
}

bool PrioritizedTaskListNode::set_left(PrioritizedTaskListNode *n) {
    left = n;
    return true;
}

PrioritizedTaskListNode *PrioritizedTaskListNode::get_left() {
    return left;
}

bool PrioritizedTaskListNode::set_right(PrioritizedTaskListNode *n) {
    right = n;
    return true;
}

PrioritizedTaskListNode *PrioritizedTaskListNode::get_right() {
    return right;
}

bool PrioritizedTaskListNode::remove_task_id(int task_id) {
    tasks.remove_all_task_id(task_id);
    return true;
}

/*bool PrioritizedTaskListNode::is_present(int v){
  Node* curr=root;
  if (curr==NULL)
    return false;

  while(curr!=NULL){
    if (curr->get_val()==v)
      return true;
    else if (curr->get_val() > v)
      curr=curr->get_left();
    else
      curr=curr->get_right();
  }
  return false;
}*/
/////////////////////////////////////////////////////////////////////////////////
class PrioritizedTaskList {
private:
    PrioritizedTaskListNode *root;

//    void preorder(PrioritizedTaskListNode*);
//    void inorder(PrioritizedTaskListNode*);
//    void postorder(PrioritizedTaskListNode*);
    void cleanUp(PrioritizedTaskListNode *);

    //helper methods
    PrioritizedTaskListNode *get_parent(int);

    PrioritizedTaskListNode *get_address(int);

    PrioritizedTaskListNode *get_largest(PrioritizedTaskListNode *);

    bool addPriorityList(int);

    void display_internal(PrioritizedTaskListNode *node);

    bool is_equal_to_internal(const PrioritizedTaskList &otherList, PrioritizedTaskListNode *node);

public:
    PrioritizedTaskList();

    PrioritizedTaskList(const PrioritizedTaskList &copy);

    ~PrioritizedTaskList();

    bool add(int priority, int taskId, char *taskName, int length);

    bool is_priority_list_present(int) const;

    bool remove_priority_list(int);

    bool remove_task_id(int, int);

    bool exist(int priority, int task_id);

//    void displayLists()
    void display();

    bool is_equal_to(const PrioritizedTaskList &otherList);

    bool does_task_list_match(int, DoublyLinkedTaskList) const;

    std::ostream &operator<<(std::ostream &os);

    bool operator==(const PrioritizedTaskList &rhs);

    PrioritizedTaskList operator=(const PrioritizedTaskList &rhs);
};

// in main cout << l1 // This will display
std::ostream &PrioritizedTaskList::operator<<(std::ostream &os) {
    display();
    return os;
}

bool PrioritizedTaskList::operator==(const PrioritizedTaskList &rhs) {
    return is_equal_to(rhs);
}

PrioritizedTaskList PrioritizedTaskList::operator=(const PrioritizedTaskList &rhs) {
    return PrioritizedTaskList(rhs);
}

/*
void PrioritizedTaskList::displayLists(){
  PrioritizedTaskListNode* curr=begin;
  int length;
  cout << endl;
  while(curr!=NULL){
    cout << "ID is:" << curr->get_task_id() << " " ;
    for(int i=0; i < curr->get_name_length(); i++){
      cout << curr->get_task_name()[i];
    }
  cout << endl;
  curr=curr->get_next();
  }
*/
void PrioritizedTaskList::display() {
    display_internal(root);
}

void PrioritizedTaskList::display_internal(PrioritizedTaskListNode *curr) {
    // inorder recursion
    if (curr == NULL) return;
    display_internal(curr->get_left());
    cout << "Priority: " << curr->get_priority() << "\t\tTask Name: " << curr->get_task_name() << "\t\tTask Id: " <<
    curr->get_task_id() << "\n";
    //cout <<
    display_internal(curr->get_right());
}

bool PrioritizedTaskList::is_equal_to(const PrioritizedTaskList &otherList) {
    if (root == NULL) {
        return false;
    }
    else {
        return is_equal_to_internal(otherList, root);
    }
}

bool PrioritizedTaskList::is_equal_to_internal(const PrioritizedTaskList &otherList, PrioritizedTaskListNode *node) {

    if (node != NULL) {
        bool does_priority_exist = otherList.is_priority_list_present(node->get_priority());

        // This one is not working
//        bool does_task_list_match = otherList.does_task_list_match(node->get_priority(), node->get_task_list());

        bool is_left_tree_equal = is_equal_to_internal(otherList, node->get_left());

        bool is_right_tree_equal = is_equal_to_internal(otherList, node->get_right());

        return (does_priority_exist && is_left_tree_equal && is_right_tree_equal);
    }
    else {
        return true;
    }
}

bool PrioritizedTaskList::does_task_list_match(int priority, DoublyLinkedTaskList taskList) const {
////////////PROBLEM/////////////////////////// 

//    if (is_priority_list_present(priority)) {
//        PrioritizedTaskListNode *priorityListNode = get_address(priority);
//        DoublyLinkedTaskList myTaskList = priorityListNode->get_task_list();
//
//        // Compare taskList with myTaskList
//    }

    return false;
}

bool PrioritizedTaskList::exist(int priority, int task_id) {
//    if (is_priority_list_present(priority)) {
//        PrioritizedTaskListNode *priorityList = get_address(priority);
//        return priorityList->does_task_id_exist(task_id);
//    }
    return false;
}

bool PrioritizedTaskList::remove_task_id(int priority, int task_id) {
//    PrioritizedTaskListNode *priorityNode = get_address(priority);
//    if (priorityNode != NULL) {
//        priorityNode->remove_task_id(task_id);
//    }
    return true;
}


bool PrioritizedTaskList::add(int priority, int taskId, char *taskName, int length) {
    if (!is_priority_list_present(priority)) {
        addPriorityList(priority);
    }
    PrioritizedTaskListNode *priorityList = get_address(priority);
    priorityList->add_task(taskId, taskName, length);
    return true;
}

bool PrioritizedTaskList::addPriorityList(int v) {
    PrioritizedTaskListNode *temp = new PrioritizedTaskListNode(v);
    if (root == NULL) {
        root = temp;
        return true;
    }
    PrioritizedTaskListNode *curr = root;
    while (curr != NULL) {
        int x = curr->get_priority();
        if (v == x) {
            delete temp;
            return false;
        }
        else if (v > x) {
            if (curr->get_right() == NULL) {
                curr->set_right(temp);
                return true;
            }
            else
                curr = curr->get_right();
        }
        else {
            if (curr->get_left() == NULL) {
                curr->set_left(temp);
                return true;
            }
            else
                curr = curr->get_left();
        }
    }
    return true;
}

PrioritizedTaskList::PrioritizedTaskList() {
    root = NULL;
}

PrioritizedTaskList::PrioritizedTaskList(const PrioritizedTaskList &copy) {
    // Copy constructor
}

PrioritizedTaskList::~PrioritizedTaskList() {
    cleanUp(root);
}

void PrioritizedTaskList::cleanUp(PrioritizedTaskListNode *curr) {
    if (curr == NULL) return;
    cleanUp(curr->get_left());
    cleanUp(curr->get_right());
    delete curr;
}

PrioritizedTaskListNode *PrioritizedTaskList::get_largest(PrioritizedTaskListNode *curr) {
    while (curr->get_right() != NULL)
        curr = curr->get_right();
    return curr;
}

PrioritizedTaskListNode *PrioritizedTaskList::get_address(int v) {
    if (!is_priority_list_present(v))
        return NULL;
    PrioritizedTaskListNode *curr = root;
    while (curr != NULL) {
        if (curr->get_priority() > v)
            curr = curr->get_left();
        else if (curr->get_priority() < v)
            curr = curr->get_right();
        else
            return curr;
    }
    return NULL;
}

PrioritizedTaskListNode *PrioritizedTaskList::get_parent(int v) {
    if (!is_priority_list_present(v))
        return NULL;

    PrioritizedTaskListNode *curr = root;
    if (v == curr->get_priority())
        return NULL;

    PrioritizedTaskListNode *parent = curr;

    while (curr != NULL) {
        if (curr->get_priority() > v) {
            parent = curr;
            curr = curr->get_left();
        }
        else if (curr->get_priority() < v) {
            parent = curr;
            curr = curr->get_right();
        }
        else
            return parent;
    }
    return NULL;
}

bool PrioritizedTaskList::is_priority_list_present(int v) const {
    PrioritizedTaskListNode *curr = root;
    if (curr == NULL)
        return false;

    while (curr != NULL) {
        if (curr->get_priority() == v)
            return true;
        else if (curr->get_priority() > v)
            curr = curr->get_left();
        else
            curr = curr->get_right();
    }
    return false;
}

bool PrioritizedTaskList::remove_priority_list(int priority) {

    if (!is_priority_list_present(priority)) {
        return false;
    }

    PrioritizedTaskListNode *curr = get_address(priority);
    PrioritizedTaskListNode *parent = get_parent(priority);

    if (curr->get_left() == NULL && curr->get_right() == NULL) {

        if (curr == root) {
            delete curr;
            root = NULL;
            return true;
        }

        if (curr->get_priority() > parent->get_priority()) {

            parent->set_right(NULL);
            delete curr;

            return true;

        } else {

            parent->set_left(NULL);
            delete curr;

            return true;
        }
    } else if (curr->get_left() == NULL && curr->get_right() != NULL) {

        //in this case, "lift" the right sub-tree.
        //NOTE: if parent is NULL then root needs to be updated
        if (curr == root) {
            PrioritizedTaskListNode *temp = root;
            root = root->get_right();
            delete temp;
            return true;
        }
        if (priority > parent->get_priority()) {

            parent->set_right(curr->get_right());
        } else {
            parent->set_left(curr->get_right());
        }

        delete curr;

        return true;

    } else if (curr->get_left() != NULL && curr->get_right() == NULL) {

        //in this case, "lift" the left sub-tree.
        if (curr == root) {
            PrioritizedTaskListNode *temp = root;
            root = root->get_left();
            delete temp;
            return true;
        }
        if (priority > parent->get_priority()) {
            parent->set_right(curr->get_left());
        } else {
            parent->set_left(curr->get_left());
        }
        delete curr;

        return true;
    } else {

        //when left and right are not null.
        //in this case, replace the content of
        //curr node with that of the largest key
        //value from curr's left sub-tree
        //(or)
        //with that of the smallest key
        //value from curr's right sub-tree

        PrioritizedTaskListNode *leaf = get_largest(curr->get_left());
        int q = leaf->get_priority();
        remove_priority_list(q);
        curr->set_priority(q);

        return true;
    }
}
////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////

int main() {
    PrioritizedTaskList tree1;
    PrioritizedTaskList tree2;

    PrioritizedTaskList tree3;
// add 362
// add_task 109
// 28s
//DoublyLinkedTaskNode::DoublyLinkedTaskNode(int id, char* name, int len){
//task_id = id;
//task_name=new char[len];
//for(int i=0;i<len;i++){
//  task_name[i]=name[i];
//}
    char name1[] = "Josh";
    char name2[] = "Amis";
    char name3[] = "Jack";
    char name4[] = "Jackie";

    tree1.add(2, 12, name1, 4);
    tree1.add(5, 13, name2, 5);
    tree1.add(6, 14, name3, 4);

    cout << "______________________________________" << "\n";
    cout << "Displaying tree1" << "\n";
    cout << "______________________________________" << "\n";
    cout << endl;
    tree1.display();
    cout << endl;


    tree2.add(8, 87, name4, 6);
    cout << "______________________________________" << "\n";
    cout << "Contents of tree2" << "\n";
    cout << "______________________________________" << "\n";
    cout << endl;
    tree2.display();

    tree3.add(8, 87, name4, 6);
    cout << "______________________________________" << "\n";
    cout << "Contents of tree3" << "\n";
    cout << "______________________________________" << "\n";
    cout << endl;
    tree3.display();

    cout << "______________________________________" << "\n";
    cout << "Is tree2 == tree3?" << "\n";
    cout << "______________________________________" << "\n";
    cout << endl;
    bool isEqual = tree2.is_equal_to(tree3);
    if (isEqual) {

        cout << " Your trees are equal" << endl;

    } else {
        cout << " Your trees are NOT equal" << endl;
    }
    cout << endl;

    cout << "______________________________________" << "\n";
    cout << "Removing priority # 5 from tree1" << "\n";
    cout << "______________________________________" << "\n";
    cout << endl;
    tree1.remove_priority_list(5);
    cout << endl;
    tree1.display();
    cout << endl << "what is up";

    return 0;
}
