class Message {
    friend class Folder;
public:
    explicit Message(const std::string &str = ""):
        contents(str) { }
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();

    void save(Folder&);
    void remove(Folder&);

private:
    std::string contents;
    std::set<Folder*> folders;

    void add_to_Folders(const Message&);
    void remove_from_Folders();
};

Message::Message(const Message &m):
    contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

Message& Message::opereator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

Message::~Message()
{
    remove_from_Folders();
}

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addmsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);//two direction deletion
}

void Message::add_to_Folders(const Message &m)
{
    for(auto f: m.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders()
{
    for (auto f:folders)
        f->remMsg(this);
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;

    for (auto f: lhs.folders)
        f->remMsg(&lhs);
    for (auto f: rhs.folders)
        f->remMsg(&rhs);
    
    swap(lhs.folders,rhs.folders);
    swap(lhs.contents,rhs.contents);

    for (auto f: lhs.folders)
        f->addMsg(&lhs);
    for (auto f: lhs.folders)
        f->addMsg(&rhs);
}


/* ---------------------------------------------------------------------








**************************************************************************








-------------------------------------------------------------------------*/

class Folder {
public:
    Folder() = default;
    Folder(const Folder&);
    Folder& operator=(const Folder& rhs);
    ~Folder();


private:
    std::set<Message*> msgs;

    void add_to_Messages(const Folder&);
    void remove_from_Messages();

    void addMsg(Message* m) { msgs.insert(m); }
    void remMsg(Message* m) { msgs.erase(m); }
}