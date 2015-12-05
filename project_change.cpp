////////////////////////////////////////////////////////////////////////////////////
class DoublyLinkedIntNode { 
  private:
    int val;
    DoublyLinkedIntNode* prev;
    DoublyLinkedIntNode* next; 
  public:
    DoublyLinkedIntNode(int);
    int get_val();
    bool set_val(int);
    bool set_next(DoublyLinkedIntNode*);
    DoublyLinkedIntNode* get_next();
    bool set_prev(DoublyLinkedIntNode*);
    DoublyLinkedIntNode* get_prev();
};

DoublyLinkedIntNode::DoublyLinkedIntNode(int v){
  val=v;
  prev=NULL;
  next=NULL;
}

int DoublyLinkedIntNode::get_val(){
  return val;
}

bool DoublyLinkedIntNode::set_val(int v){
  val=v;
  return true;
}

bool DoublyLinkedIntNode::set_next(DoublyLinkedIntNode* n){
  next=n;
  return true;
}

bool DoublyLinkedIntNode::set_prev(DoublyLinkedIntNode* n){
  prev=n;
  return true;
}

DoublyLinkedIntNode* DoublyLinkedIntNode::get_next(){
  return next;
}

DoublyLinkedIntNode* DoublyLinkedIntNode::get_prev(){
  return prev;
}
////////////////////////////////////////////////////////////////////////////////////
class DoublyLinkedIntList {
  private:
    DoublyLinkedIntNode* begin;

  public:
    DoublyLinkedIntList();
    ~DoublyLinkedIntList();
    bool add(int);
    bool remove_all(int);
    bool remove_at(int);
};
bool DoublyLinkedIntList::remove_all(int v){
  DoublyLinkedIntNode* curr=begin;
  while(curr!=NULL){
    DoublyLinkedIntNode* next=curr->get_next();
    if(curr->get_val()==v){
      DoublyLinkedIntNode* prev=curr->get_prev();
      if(prev==NULL){
        begin=next;
        begin->set_prev(NULL);
      }
      else{
        prev->set_next(next);
      }
      delete curr;
    }
    curr=next;
  }
  return true;
}

bool DoublyLinkedIntList::remove_at(int index) {
  int curr_index = 0;
  DoublyLinkedIntNode * curr_node = begin;
  while (curr_node != NULL) {
    if (curr_index == index) {
      break;
    }
    curr_index++;
    curr_node = curr_node->get_next();
  }

  if (curr_node != NULL) {
    DoublyLinkedIntNode* next_node = curr_node->get_next();
    DoublyLinkedIntNode* prev_node = curr_node->get_prev();
    if(prev_node == NULL){
      begin = next_node;
      begin->set_prev(NULL);
    }
    else{
      prev_node->set_next(next_node);
    }
    delete curr_node;
  }

  return true;
}

DoublyLinkedIntList::DoublyLinkedIntList(){
  begin=NULL;
}
bool DoublyLinkedIntList::add(int v){
  DoublyLinkedIntNode* temp=new DoublyLinkedIntNode(v);
  if (temp==NULL)
    return false;
  if(begin==NULL){
    begin=temp;
    return true;
  }

  DoublyLinkedIntNode* curr=begin;
  while(curr->get_next()!=NULL)
    curr=curr->get_next();

  curr->set_next(temp);
  temp->set_prev(curr);
  return true;
}
DoublyLinkedIntList::~DoublyLinkedIntList(){
  DoublyLinkedIntNode* temp=begin;
  while(temp!=NULL){
    DoublyLinkedIntNode* save=temp->get_next();
    cout << "Deleting " << temp->get_val() << endl;
    delete temp;
    temp=save;
  }
}
////////////////////////////////////////////////////////////////////////////////
class DoublyLinkedStringtNode { 
  private:
    char* val;
    DoublyLinkedStringtNode* prev;
    DoublyLinkedStringtNode* next; 
  public:
    DoublyLinkedStringtNode(char*, int);
    char* get_val();
    bool set_val(char*, int);
    bool set_next(DoublyLinkedStringtNode*);
    DoublyLinkedStringtNode* get_next();
    bool set_prev(DoublyLinkedStringtNode*);
    DoublyLinkedStringtNode* get_prev();
};

DoublyLinkedStringtNode::DoublyLinkedStringtNode(char* v, int length){
  val=new char [length];
  for(int i=0;i<length;i++){
    val[i]=v[i];
  }
  prev=NULL;
  next=NULL;
}

char* DoublyLinkedStringtNode::get_val(){
  return val;
}

bool DoublyLinkedStringtNode::set_val(char* v, int length){
  if(val!=NULL){
    delete val;
  }
  val=new char [length];
  for(int i=0;i<length;i++){
    val[i]=v[i];
  }
  return true;
}

bool DoublyLinkedStringtNode::set_next(DoublyLinkedStringtNode* n){
  next=n;
  return true;
}

bool DoublyLinkedStringtNode::set_prev(DoublyLinkedStringtNode* n){
  prev=n;
  return true;
}

DoublyLinkedStringtNode* DoublyLinkedStringtNode::get_next(){
  return next;
}

DoublyLinkedStringtNode* DoublyLinkedStringtNode::get_prev(){
  return prev;
}
/////////////////////////////////////////////////////////////////////////////////

//class DoublyLinkedStringList { };
class DoublyLinkedStringList {
  private:
    DoublyLinkedStringtNode* begin;

  public:
    DoublyLinkedStringList();
    ~DoublyLinkedStringList();
    bool add(char*, int);
    bool remove_all(char*);
    bool remove_at(int);
};

DoublyLinkedStringList::DoublyLinkedStringList(){
  begin=NULL;
}
bool DoublyLinkedStringList::remove_all(char* v){
  DoublyLinkedStringtNode* curr=begin;
  while(curr!=NULL){
    DoublyLinkedStringtNode* next=curr->get_next();
    if(strcmp(curr->get_val(), v) == 0){
      DoublyLinkedStringtNode* prev=curr->get_prev();
      if(prev==NULL){
        begin=next;
        begin->set_prev(NULL);
      }
      else{
        prev->set_next(next);
      }
      delete curr;
    }
    curr=next;
  }
  return true;
}

bool DoublyLinkedStringList::remove_at(int index) {
  int curr_index = 0;
  DoublyLinkedStringtNode * curr_node = begin;
  while (curr_node != NULL) {
    if (curr_index == index) {
      break;
    }
    curr_index++;
    curr_node = curr_node->get_next();
  }

  if (curr_node != NULL) {
    DoublyLinkedStringtNode* next_node = curr_node->get_next();
    DoublyLinkedStringtNode* prev_node = curr_node->get_prev();
    if(prev_node == NULL){
      begin = next_node;
      begin->set_prev(NULL);
    }
    else{
      prev_node->set_next(next_node);
    }
    delete curr_node;
  }

  return true;
}

bool DoublyLinkedStringList::add(char* v, int length){
  DoublyLinkedStringtNode* temp=new DoublyLinkedStringtNode(v,length);
  if (temp==NULL)
    return false;
  if(begin==NULL){
    begin=temp;
    return true;
  }

  DoublyLinkedStringtNode* curr=begin;
  while(curr->get_next()!=NULL)
    curr=curr->get_next();

  curr->set_next(temp);
  temp->set_prev(curr);
  return true;
}
DoublyLinkedStringList::~DoublyLinkedStringList(){
  DoublyLinkedStringtNode* temp=begin;
  while(temp!=NULL){
    DoublyLinkedStringtNode* save=temp->get_next();
    cout << "Deleting " << temp->get_val() << endl;
    delete temp;
    temp=save;
  }
}
