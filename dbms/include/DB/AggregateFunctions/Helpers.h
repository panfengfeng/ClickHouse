#pragma once

#include <DB/DataTypes/DataTypeDate.h>
#include <DB/DataTypes/DataTypeDateTime.h>
#include <DB/DataTypes/DataTypeString.h>
#include <DB/DataTypes/DataTypeFixedString.h>
#include <DB/DataTypes/DataTypesNumberFixed.h>
#include <DB/DataTypes/DataTypeEnum.h>
#include <DB/AggregateFunctions/IAggregateFunction.h>


namespace DB
{

/** Создать агрегатную функцию с числовым типом в параметре шаблона, в зависимости от типа аргумента.
  */
template <template <typename> class AggregateFunctionTemplate>
static IAggregateFunction * createWithNumericType(const IDataType & argument_type)
{
	     if (typeid_cast<const DataTypeUInt8 	*>(&argument_type))	return new AggregateFunctionTemplate<UInt8>;
	else if (typeid_cast<const DataTypeUInt16 	*>(&argument_type))	return new AggregateFunctionTemplate<UInt16>;
	else if (typeid_cast<const DataTypeUInt32 	*>(&argument_type))	return new AggregateFunctionTemplate<UInt32>;
	else if (typeid_cast<const DataTypeUInt64 	*>(&argument_type))	return new AggregateFunctionTemplate<UInt64>;
	else if (typeid_cast<const DataTypeInt8 	*>(&argument_type))	return new AggregateFunctionTemplate<Int8>;
	else if (typeid_cast<const DataTypeInt16 	*>(&argument_type))	return new AggregateFunctionTemplate<Int16>;
	else if (typeid_cast<const DataTypeInt32 	*>(&argument_type))	return new AggregateFunctionTemplate<Int32>;
	else if (typeid_cast<const DataTypeInt64 	*>(&argument_type))	return new AggregateFunctionTemplate<Int64>;
	else if (typeid_cast<const DataTypeFloat32 *>(&argument_type))	return new AggregateFunctionTemplate<Float32>;
	else if (typeid_cast<const DataTypeFloat64 *>(&argument_type))	return new AggregateFunctionTemplate<Float64>;
	else if (typeid_cast<const DataTypeEnum8 	*>(&argument_type))	return new AggregateFunctionTemplate<UInt8>;
	else if (typeid_cast<const DataTypeEnum16 	*>(&argument_type))	return new AggregateFunctionTemplate<UInt16>;
	else
		return nullptr;
}

template <template <typename, typename> class AggregateFunctionTemplate, class Data>
static IAggregateFunction * createWithNumericType(const IDataType & argument_type)
{
	     if (typeid_cast<const DataTypeUInt8 	*>(&argument_type))	return new AggregateFunctionTemplate<UInt8, Data>;
	else if (typeid_cast<const DataTypeUInt16 	*>(&argument_type))	return new AggregateFunctionTemplate<UInt16, Data>;
	else if (typeid_cast<const DataTypeUInt32 	*>(&argument_type))	return new AggregateFunctionTemplate<UInt32, Data>;
	else if (typeid_cast<const DataTypeUInt64 	*>(&argument_type))	return new AggregateFunctionTemplate<UInt64, Data>;
	else if (typeid_cast<const DataTypeInt8 	*>(&argument_type))	return new AggregateFunctionTemplate<Int8, Data>;
	else if (typeid_cast<const DataTypeInt16 	*>(&argument_type))	return new AggregateFunctionTemplate<Int16, Data>;
	else if (typeid_cast<const DataTypeInt32 	*>(&argument_type))	return new AggregateFunctionTemplate<Int32, Data>;
	else if (typeid_cast<const DataTypeInt64 	*>(&argument_type))	return new AggregateFunctionTemplate<Int64, Data>;
	else if (typeid_cast<const DataTypeFloat32 *>(&argument_type))	return new AggregateFunctionTemplate<Float32, Data>;
	else if (typeid_cast<const DataTypeFloat64 *>(&argument_type))	return new AggregateFunctionTemplate<Float64, Data>;
	else if (typeid_cast<const DataTypeEnum8 	*>(&argument_type))	return new AggregateFunctionTemplate<UInt8, Data>;
	else if (typeid_cast<const DataTypeEnum16 	*>(&argument_type))	return new AggregateFunctionTemplate<UInt16, Data>;
	else
		return nullptr;
}


template <template <typename, typename> class AggregateFunctionTemplate, template <typename> class Data>
static IAggregateFunction * createWithNumericType(const IDataType & argument_type)
{
	     if (typeid_cast<const DataTypeUInt8 	*>(&argument_type))	return new AggregateFunctionTemplate<UInt8, Data<UInt8> >;
	else if (typeid_cast<const DataTypeUInt16 	*>(&argument_type))	return new AggregateFunctionTemplate<UInt16, Data<UInt16> >;
	else if (typeid_cast<const DataTypeUInt32 	*>(&argument_type))	return new AggregateFunctionTemplate<UInt32, Data<UInt32> >;
	else if (typeid_cast<const DataTypeUInt64 	*>(&argument_type))	return new AggregateFunctionTemplate<UInt64, Data<UInt64> >;
	else if (typeid_cast<const DataTypeInt8 	*>(&argument_type))	return new AggregateFunctionTemplate<Int8, Data<Int8> >;
	else if (typeid_cast<const DataTypeInt16 	*>(&argument_type))	return new AggregateFunctionTemplate<Int16, Data<Int16> >;
	else if (typeid_cast<const DataTypeInt32 	*>(&argument_type))	return new AggregateFunctionTemplate<Int32, Data<Int32> >;
	else if (typeid_cast<const DataTypeInt64 	*>(&argument_type))	return new AggregateFunctionTemplate<Int64, Data<Int64> >;
	else if (typeid_cast<const DataTypeFloat32 *>(&argument_type))	return new AggregateFunctionTemplate<Float32, Data<Float32> >;
	else if (typeid_cast<const DataTypeFloat64 *>(&argument_type))	return new AggregateFunctionTemplate<Float64, Data<Float64> >;
	else if (typeid_cast<const DataTypeEnum8 	*>(&argument_type))	return new AggregateFunctionTemplate<UInt8, Data<UInt8> >;
	else if (typeid_cast<const DataTypeEnum16 	*>(&argument_type))	return new AggregateFunctionTemplate<UInt16, Data<UInt16> >;
	else
		return nullptr;
}


/** Для шаблона с двумя аргументами.
  */
template <typename FirstType, template <typename, typename> class AggregateFunctionTemplate>
static IAggregateFunction * createWithTwoNumericTypesSecond(const IDataType & second_type)
{
	     if (typeid_cast<const DataTypeUInt8 	*>(&second_type))	return new AggregateFunctionTemplate<FirstType, UInt8>;
	else if (typeid_cast<const DataTypeUInt16 	*>(&second_type))	return new AggregateFunctionTemplate<FirstType, UInt16>;
	else if (typeid_cast<const DataTypeUInt32 	*>(&second_type))	return new AggregateFunctionTemplate<FirstType, UInt32>;
	else if (typeid_cast<const DataTypeUInt64 	*>(&second_type))	return new AggregateFunctionTemplate<FirstType, UInt64>;
	else if (typeid_cast<const DataTypeInt8 	*>(&second_type))	return new AggregateFunctionTemplate<FirstType, Int8>;
	else if (typeid_cast<const DataTypeInt16 	*>(&second_type))	return new AggregateFunctionTemplate<FirstType, Int16>;
	else if (typeid_cast<const DataTypeInt32 	*>(&second_type))	return new AggregateFunctionTemplate<FirstType, Int32>;
	else if (typeid_cast<const DataTypeInt64 	*>(&second_type))	return new AggregateFunctionTemplate<FirstType, Int64>;
	else if (typeid_cast<const DataTypeFloat32 	*>(&second_type))	return new AggregateFunctionTemplate<FirstType, Float32>;
	else if (typeid_cast<const DataTypeFloat64 	*>(&second_type))	return new AggregateFunctionTemplate<FirstType, Float64>;
	else if (typeid_cast<const DataTypeEnum8 	*>(&second_type))	return new AggregateFunctionTemplate<FirstType, UInt8>;
	else if (typeid_cast<const DataTypeEnum16 	*>(&second_type))	return new AggregateFunctionTemplate<FirstType, UInt16>;
	else
		return nullptr;
}

template <template <typename, typename> class AggregateFunctionTemplate>
static IAggregateFunction * createWithTwoNumericTypes(const IDataType & first_type, const IDataType & second_type)
{
	     if (typeid_cast<const DataTypeUInt8 	*>(&first_type))	return createWithTwoNumericTypesSecond<UInt8, AggregateFunctionTemplate>(second_type);
	else if (typeid_cast<const DataTypeUInt16 	*>(&first_type))	return createWithTwoNumericTypesSecond<UInt16, AggregateFunctionTemplate>(second_type);
	else if (typeid_cast<const DataTypeUInt32 	*>(&first_type))	return createWithTwoNumericTypesSecond<UInt32, AggregateFunctionTemplate>(second_type);
	else if (typeid_cast<const DataTypeUInt64 	*>(&first_type))	return createWithTwoNumericTypesSecond<UInt64, AggregateFunctionTemplate>(second_type);
	else if (typeid_cast<const DataTypeInt8 	*>(&first_type))	return createWithTwoNumericTypesSecond<Int8, AggregateFunctionTemplate>(second_type);
	else if (typeid_cast<const DataTypeInt16 	*>(&first_type))	return createWithTwoNumericTypesSecond<Int16, AggregateFunctionTemplate>(second_type);
	else if (typeid_cast<const DataTypeInt32 	*>(&first_type))	return createWithTwoNumericTypesSecond<Int32, AggregateFunctionTemplate>(second_type);
	else if (typeid_cast<const DataTypeInt64 	*>(&first_type))	return createWithTwoNumericTypesSecond<Int64, AggregateFunctionTemplate>(second_type);
	else if (typeid_cast<const DataTypeFloat32 	*>(&first_type))	return createWithTwoNumericTypesSecond<Float32, AggregateFunctionTemplate>(second_type);
	else if (typeid_cast<const DataTypeFloat64 	*>(&first_type))	return createWithTwoNumericTypesSecond<Float64, AggregateFunctionTemplate>(second_type);
	else if (typeid_cast<const DataTypeEnum8 	*>(&first_type))	return createWithTwoNumericTypesSecond<UInt8, AggregateFunctionTemplate>(second_type);
	else if (typeid_cast<const DataTypeEnum16 	*>(&first_type))	return createWithTwoNumericTypesSecond<UInt16, AggregateFunctionTemplate>(second_type);
	else
		return nullptr;
}

}
