#ifndef SERIALIZE_HPP_
#define SERIALIZE_HPP_

#include <iostream>


class Data
{
	private:
		int id;
	public:
		Data (int id);
		int getId (void) const;
};

#endif 