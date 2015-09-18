#ifndef dogm163_h
#define dogm163_h

class iDogm163 {
  public:
    virtual bool write_command(std::uint8_t command) = 0;
};


#endif

