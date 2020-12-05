#pragma once

#ifndef SDI_libBasicObjectsHeader_incleder
#define SDI_libBasicObjectsHeader_incleder

#include <deque>
#include <vector>
#include <stdarg.h>

#include "../libCore.h"
#include "Types.h"

namespace SDI
{	template<typename type, typename args>
	bool isEOr(const type& what, const args& argsv, ...)
	{	va_list farg;
		va_start(farg, argsv);
		
		std::vector<bool> ra;

		for (char *c = farg; *c; c++)
		{ ra = (what == va_arg(farg, args)); }

		bool r = false;
		for (bool var : ra) if (var, r = var) break;

		return r; }

	template<typename type, typename args>
	bool isEAnd(const type& what, const args& argsv, ...)
	{	va_list farg;
		va_start(farg, argsv);

		std::vector<bool> ra;

		for (char *c = farg; *c; c++)
		{ ra = (what == va_arg(farg, args)); }

		bool r = true;
		for (bool var : ra) if (!var, r = var) break;

		return r; }

	template<typename basicType>
	__interface IBasic_SDIFondationObject
	{	virtual IBasic_SDIFondationObject* getPointer();
		virtual const IBasic_SDIFondationObject* getConstPointer() const;

		virtual uint getFlags() const;
		virtual void setFlags(uint flags);
		virtual void clearFlags(); };

	template<typename storageType>
	struct Basic_SDIDataStorage : IBasic_SDIFondationObject<storageType>
	{protected: storageType* data = nullptr;
				ubyte flags = 0;

				Basic_SDIDataStorage() NULLBODY
				Basic_SDIDataStorage(Basic_SDIDataStorage&) NULLBODY
				Basic_SDIDataStorage(const Basic_SDIDataStorage&) NULLBODY

	public:		virtual ~Basic_SDIDataStorage() = default;
		
				virtual void swapData(Basic_SDIDataStorage& obj)
				{	storageType* dataCopy = this->data;
					this->data = obj.data;
					obj.data = dataCopy;
					dataCopy = nullptr; };
				virtual void swapAttribs(Basic_SDIDataStorage& obj)
				{	ubyte attribCopy = this->flags;
					this->flags = obj.flags;
					obj.flags = attribCopy; }

				virtual void moveData(Basic_SDIDataStorage<storageType>*& obj)
				{	auto s = this->flags;
					this->~Basic_SDIDataStorage();	

					this->flags = s;
					
					this->data = obj->data;
					obj->~Basic_SDIDataStorage();
					obj = nullptr; }
				virtual void moveAttribs(Basic_SDIDataStorage<storageType>*& obj)
				{	this->flags = obj->flags;
					obj->~Basic_SDIDataStorage();
					obj = nullptr; }
				virtual void moveObject(Basic_SDIDataStorage<storageType>*& obj)
				{	this->~Basic_SDIDataStorage();
					
					this->data = obj->data;
					this->flags = obj->flags;
					obj->~Basic_SDIDataStorage();
					obj = nullptr; }

				virtual void copyData(const Basic_SDIDataStorage<storageType>& obj)
				{	auto s = this->flags;
					this->~Basic_SDIDataStorage();	

					this->flags = s;
					this->data = obj.data; }
				virtual void copyAttribs(const Basic_SDIDataStorage<storageType>& obj)
				{ this->flags = obj.flags; }
				virtual void copyObject(const Basic_SDIDataStorage<storageType>& obj)
				{	this->~Basic_SDIDataStorage();
					
					this->data = obj.data;
					this->flags = obj.flags; }

				virtual void setData(storageType* nData) = 0;
				virtual void clearData() = 0;

				virtual storageType* getDataPtr()
				{ return this->data; }
				virtual storageType* getDataConstPtr() const
				{	const auto r = this->data;
					return r; }

				virtual uint getFlags() const override
				{ return this->flags; }

				virtual void operator>= (Basic_SDIDataStorage& object) = 0;
				virtual void operator<= (Basic_SDIDataStorage& object) = 0;

				virtual uint operator! () const = 0;
				virtual storageType* operator &() const = 0;

				virtual void operator= (const Basic_SDIDataStorage<storageType>& obj) = 0; };

	template<typename storageType>
	class Basic_SDIRef : public Basic_SDIDataStorage<storageType>
	{ public:	Basic_SDIRef(storageType* pointer = nullptr, ubyte flags = 0b00)
				{	this->data = pointer;
					this->flags = flags; }
				Basic_SDIRef(Basic_SDIRef& obj)
				{ this->moveObject(obj); }
				Basic_SDIRef(const Basic_SDIRef& obj)
				{ this->copyObject(obj); }

				~Basic_SDIRef() override
				{ this->clearData(); }

				void setData(storageType* nData) override
				{	this->clearData();
					this->data = nData; }
				void clearData() override
				{	if (this->flags & 0b10 && this->data != nullptr)
					{ delete this->data; }

					this->data = nullptr;}

				SDI::IBasic_SDIFondationObject<storageType>* getPointer() override
				{	IBasic_SDIFondationObject<storageType>* r = this;
					return r; }
				const SDI::IBasic_SDIFondationObject<storageType>* getConstPointer() const override
				{	const IBasic_SDIFondationObject<storageType>* r = this;
					return r; }

				void setFlags(uint flags) override
				{ this->flags = flags; }
				void clearFlags() override 
				{ this->flags &= 0b01; }

				void operator>= (Basic_SDIDataStorage<storageType>& object) override
				{ this->flags = object.getFlags(); }
				void operator<= (Basic_SDIDataStorage<storageType>& object) override
				{ this->data = object.getDataPtr(); }
				void operator= (const Basic_SDIDataStorage<storageType>& obj) override
				{ this->copyObject(obj); }

				storageType* operator& () const override
				{ return this->getDataConstPtr(); }

				uint operator! () const override
				{ return this->flags; }	}; 

	template<typename storageType>
	class Basic_SDIDictionary : public Basic_SDIDataStorage<std::deque<storageType>>
	{ public:	Basic_SDIDictionary(ubyte flags = 0b0)
				{	this->flags = flags;
					this->data = new std::deque<storageType>{}; }
				Basic_SDIDictionary(Basic_SDIDictionary& obj)
				{ this->moveObject(obj); }
				Basic_SDIDictionary(const Basic_SDIDictionary& obj)
				{ this->copyObject(obj); }
				~Basic_SDIDictionary() override
				{	if (this->flags & 0b10 && this->data != nullptr)
					{ delete this->data; }

					this->data = nullptr; }

				void setData(std::deque<storageType>* nData) override
				{	this->clearData();
					this->data = nData; }
				void clearData() override
				{	if (this->flags & 0b10 && this->data != nullptr)
					{ delete this->data; }

					this->data = nullptr;}

				SDI::IBasic_SDIFondationObject<std::deque<storageType>>* getPointer() override
				{	IBasic_SDIFondationObject<std::deque<storageType>>* r = this;
					return r; }
				const SDI::IBasic_SDIFondationObject<std::deque<storageType>>* getConstPointer() const override
				{	const IBasic_SDIFondationObject<std::deque<storageType>>* r = this;
					return r; }

				void setFlags(uint flags) override
				{ this->flags = flags; }
				void clearFlags() override 
				{ this->flags &= 0b01; }

				void emplaceData(const storageType& data)
				{ this->data->push_back(data); }
				bool isFind(const storageType& data) const
				{	bool r = false;
					for (auto var : this->data)
					{	r = (var == data);
						if (r) break; }

					return r; }

				void operator>= (Basic_SDIDataStorage<std::deque<storageType>>& object) override
				{ this->flags = object.getFlags(); }
				void operator<= (Basic_SDIDataStorage<std::deque<storageType>>& object) override
				{	auto s = this->flags;
					this->~Basic_SDIDictionary();	

					this->flags = s;
					this->data = object.getDataPtr(); }
				void operator= (const Basic_SDIDataStorage<std::deque<storageType>>& obj) override
				{ this->copyObject(obj); }

				std::deque<storageType>* operator& () const override
				{ return this->getDataConstPtr(); }
				Basic_SDIDictionary<storageType>* operator* ()
				{ return this; }

				uint operator! () const override
				{ return this->flags; } }; }

#endif // !SDI_libBasicObjectsHeader_incleder
