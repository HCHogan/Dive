class Stream {
public:
    virtual void Read() = 0;
    virtual void Write() = 0; 
};

class DecoratorStream : public Stream{
protected:
    Stream* stream;
public:
    DecoratorStream(Stream* stm) : stream(stm) {}
};

class FileStream : public Stream {
    virtual void Read() {
        // do something
    }
    virtual void Write() {

    }
};

class CryptoStream : public DecoratorStream {
public:
    CryptoStream(Stream* stm): DecoratorStream(stm) { }
    virtual void Read() {
        stream->Read();
        // crypto
    }
    virtual void Write() {
        stream->Write();
        // crypto
    }
};

class BufferedStream : public DecoratorStream {
public:
    BufferedStream(Stream* stm): DecoratorStream(stm) { }
    virtual void Read() {
        stream->Read();
        //Buffer
    }
    virtual void Write() {
        stream->Write();
        //Buffer
    }
};

void Process() {
    FileStream* fs1 =new FileStream();
    CryptoStream* fs2 = new CryptoStream(fs1);
    BufferedStream* fs3 = new BufferedStream(fs2);
}
