#include <iostream>



class Protocol
{
	protected:
		std::string name;
	public:
		virtual void WichProtocol (void)
		{
			std::cout << "Base protocol" << std::endl;
		}
		std::string getName (void)
		{
			return (this->name);
		};
	Protocol &operator = (Protocol const &assign)
	{
		std::cout << "copy assignement " << std::endl;
		this->name = assign.name;
		return (*this);
	}
	Protocol ()
	{
		this->name = "BASE";
		std::cout << "Base Constructor" << std::endl ;
	}
	~Protocol ()
	{
		std::cout << "Deleting Base " << std::endl;
	}
};

class Dhcp : public Protocol
{
	private:
		std::string name;
	public:
		void WichProtocol (void)
		{
			std::cout << "DHCP protocol" << std::endl;
		}
	Dhcp ()
	{
		std::cout << "Dhcp Constructor" << std::endl ;
	}
	~Dhcp ()
	{
		std::cout << "Deleting DHCP " << std::endl;
	}
};

class Tcp : public Protocol
{
	private:
		std::string name;
		int id;
	public:
		void WichProtocol (void)
		{
			std::cout << "TCP protocol" << std::endl;
		}
		int getId (void)
		{
			return (this->id);
		};
	Tcp (std::string name, int id)
	{
		this->name = name;
		this->id = id;
		std::cout << "TCP Constructor" << std::endl ;
	}
	
};

class Animal {
    public:
    virtual ~Animal() {
        std::cout << "Deleting an Animal" << std::endl;
    }
};
class Cat:public Animal {
    public:
    ~Cat() {
        std::cout << "Deleting an Animal name Cat" << std::endl;
    }
};

void establishConnection (Protocol *d)
{
	d->WichProtocol ();
	std::cout << "Establishing connection" << std::endl;
}

int main ()
{
	Tcp tcp("TCP", 41515);
	Protocol *base = &tcp;
	std::cout << base->getName() << std::endl;
	std::cout << base->getId () << std::endl;
}