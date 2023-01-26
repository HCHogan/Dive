class Stream {
public:
    virtual void Read() = 0;
    virtual void Write() = 0; 
};

class DecoratorStream : public Stream{
protected:
    DecoratorStream(Stream* stm) : stream(stm) {}
    Stream* stream;
};

class FileStream : public Stream {
    virtual void Read() {
        // do something
    }
    virtual void Write() {

    }
};

class CryptoStream : public DecoratorStream {
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
    
}
