Three (textbook) Pillars of Object-Oriented Languages:
1. Encapsulation
2. Inheritance
3. Polymorphism

namespace std
{
  class string{};
}



======================= INHERITANCE & POLYMORPHISM =====================

 IS-A relationship: every object of a child class IS an object of the parent class
   
  Polymorphism is implemented using V-Table lookups
 
class Birdie
{
protected:
    int m_identifier;
    std::string m_name;

public:
    
    virtual ~Birdie() {}
    virtual void sayHoot() const;
   
};


class FlyingBirdie : public Birdie
{
private:
   const int m_number_of_wingies;

public:
    virtual ~FlyingBirdie() {}
    virtual void sayHoot() const
    {
       base::sayHoot();
       std::cout << "I don't give a flying hoot!" << std::endl;
    }
   
    void fly() {
       std::cout << m_name << "is flying" << std::endl;
    }
};

b-----> [ int | std::string  | const int ]
        | <- Birdie ->       |
        | <-------  FlyingBirdie ------->| 
main()
{
    FlyingBirdie fb;
    fb.fly();
    fb.sayHoot();
  
   // polymorphism (dynamic)
    Birdie * b = new FlyingBirdie();
    b->sayHoot(); // will call the FlyingBirdie's sayHoot() BECAUSE it is virtual!
    delete b;     // will call the FlyingBirdie's destructor BECAUSE it is  virtual!
}
