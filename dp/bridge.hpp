#include <string>

class MessagerImp {
public:
    virtual void PlaySound() = 0;
    virtual void WriteText() = 0;
    virtual void DrawShape() = 0;
    virtual void Connect() = 0;

    MessagerImp(){}

};

class Messager {
public: 
    MessagerImp* messagerImp;
    Messager(MessagerImp* mmp) : messagerImp(mmp) { }
public:
    virtual void LogIn(::std::string username, ::std::string password) = 0;
    virtual void SendMessage(::std::string message) = 0;
    virtual void SendPicture() = 0;
};

class PCMessagerImp : public MessagerImp{
public:
    virtual void LogIn() { }
    virtual void Connect() { }
    virtual void WriteText() { }
    virtual void PlaySound() { }
    virtual void DrawShape() { }
};

class MobileMessagerImp : public MessagerImp{
public:
    virtual void LogIn() { }
    virtual void Connect() { }
    virtual void WriteText() { }
    virtual void PlaySound() { }
    virtual void DrawShape() { }
};

class MessagerLite : public Messager{
public:
    MessagerLite(MessagerImp* mmp):Messager(mmp) { }

    virtual void LogIn(::std::string username, ::std::string password) {
        messagerImp->Connect();
        //==========
    }
    virtual void SendMessage(::std::string message) {
        messagerImp->WriteText();
        //===========
    }
    virtual void SendPicture() {
        messagerImp->DrawShape();
        //=========
    }
};

void Process() {
    MessagerImp* mImp = new PCMessagerImp();
    Messager *m = new MessagerLite(mImp);
}
