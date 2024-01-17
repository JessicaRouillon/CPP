#include "../inc/Serializer.hpp"

int	main()
{
	Data	data = {.value = 42};

	uintptr_t	serializedData = Serializer::serialize(&data);
	Data	*deserializedData = Serializer::deserialize(serializedData);

	std::cout << "\033[34mCompare Values\033[0m" << std::endl;
	std::cout << "Data = " << data.value << std::endl;
	std::cout << "Serialized Data = " << serializedData << " (memory address of data.value)" << std::endl;
	std::cout << "Deserialized Data = " << deserializedData->value << " (back to original value)" << std::endl;
	std::cout << std::endl;

	data.value = 0;
	std::cout << "\033[34mCompare Values\033[0m" << std::endl;
	std::cout << "Data = " << data.value << std::endl;
	std::cout << "Serialized Data = " << serializedData << " (memory address of data.value)" << std::endl;
	std::cout << "Deserialized Data = " << deserializedData->value << " (back to original value)" << std::endl;
	std::cout << std::endl;

	return (0);
}
