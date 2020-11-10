#pragma once
#ifndef GROWING_CONTAINER_H
#define GROWING_CONTAINER_H
#include <exception>

template<typename DataType, int initialSize = 5, int increasingCoefficient = 2>

class GrowingContainer {

public:
	GrowingContainer();
	~GrowingContainer();
	void ResizeArray();
	void Add(const DataType& o);
	DataType& operator[](int index);
	DataType operator[](int index) const;
	unsigned int Count() const;
	void AddTo(int index, const DataType& o);
	void Remove(int index);
	


private:
	DataType** arrayObjects;
	unsigned int sizeArray;
	unsigned int numberValidElements;
	bool IsPlaceInArray() const;
};

template<typename DataType, int initialSize, int increasingCoefficient>
GrowingContainer<DataType, initialSize, increasingCoefficient>::GrowingContainer()
{
	sizeArray = initialSize;
	numberValidElements = 0;
	arrayObjects = new DataType*[sizeArray];
}

template<typename DataType, int initialSize, int increasingCoefficient>
GrowingContainer<DataType, initialSize, increasingCoefficient>::~GrowingContainer()
{
	for (unsigned int i = 0; i < numberValidElements; i++) {
		delete arrayObjects[i];
	}
	delete[] arrayObjects;
}
template<typename DataType, int initialSize, int increasingCoefficient>
bool GrowingContainer<DataType, initialSize, increasingCoefficient>::IsPlaceInArray() const
{
	if (numberValidElements == sizeArray) {
		return false;
	}
	return true;
}
template<typename DataType, int initialSize, int increasingCoefficient>
void GrowingContainer<DataType, initialSize, increasingCoefficient>::ResizeArray()
{
	int newSize = sizeArray * increasingCoefficient;
	DataType** tmpArray = new DataType*[newSize];
	for (int i = 0; i < numberValidElements; i++) {
		tmpArray[i] = arrayObjects[i];
	}
	sizeArray = newSize;
	delete[] arrayObjects;
	arrayObjects = tmpArray;
}
template<typename DataType, int initialSize, int increasingCoefficient>
void GrowingContainer<DataType, initialSize, increasingCoefficient>::Add(const DataType& o)
{
	if (IsPlaceInArray()){
		arrayObjects[numberValidElements++] = new DataType(o);
	}
	else {
		ResizeArray();
		arrayObjects[numberValidElements++] = new DataType(o);
	}
}
template<typename DataType, int initialSize, int increasingCoefficient>
DataType& GrowingContainer<DataType, initialSize, increasingCoefficient>::operator[](int index)
{
	if(numberValidElements != 0 && index < numberValidElements && index >= 0){
		return *arrayObjects[index];
	}
	throw std::invalid_argument("This index is not in array!");
}
template<typename DataType, int initialSize, int increasingCoefficient>
inline DataType GrowingContainer<DataType, initialSize, increasingCoefficient>::operator[](int index) const
{
	if (numberValidElements != 0 && index < numberValidElements && index >= 0) {
		return *arrayObjects[index];
	}
	throw std::invalid_argument("This index is not in array!");
}
template<typename DataType, int initialSize, int increasingCoefficient>
unsigned int GrowingContainer<DataType, initialSize, increasingCoefficient>::Count() const
{
	return numberValidElements;
}
template<typename DataType, int initialSize, int increasingCoefficient>
void GrowingContainer<DataType, initialSize, increasingCoefficient>::AddTo(int index, const DataType& o)
{
	if (numberValidElements == sizeArray) {
		ResizeArray();
	}
	if (numberValidElements == index) {
		Add(o);
	}else {
		DataType tmpOldIndex = *arrayObjects[index];
		*arrayObjects[index] = o;
		DataType tmp;
		for(unsigned int i = index; i < numberValidElements-1; i++) {
			tmp = *arrayObjects[i+1];	
			*arrayObjects[i+1] = tmpOldIndex;
			tmpOldIndex = tmp;
		}
		Add(tmpOldIndex);
	}
}
template<typename DataType, int initialSize, int increasingCoefficient>
void GrowingContainer<DataType, initialSize, increasingCoefficient>::Remove(int index)
{
	delete arrayObjects[index];
	for (unsigned int i = index; i < numberValidElements-1; i++) {
		arrayObjects[i] = arrayObjects[i + 1];
	}
	numberValidElements--;
	arrayObjects[numberValidElements] = NULL;

}
#endif // !GROWING_CONTAINER_H

