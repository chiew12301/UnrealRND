// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

template<typename T>
class TSingleton
{
public:
	static T& GetInstance()
	{
		static T Instance;
		return Instance;
	}

protected:
	TSingleton() {}
	virtual ~TSingleton() {}

private:
	////Deletes the copy constructor.
	TSingleton(const TSingleton&) = delete;
	//Deletes the copy assignment operator.
	TSingleton& operator = (const TSingleton&) = delete;
	//Deletes the move constructor.
	TSingleton(TSingleton&&) = delete;
	//Deletes the move assignment operator.
	TSingleton& operator = (TSingleton&&) = delete;
};