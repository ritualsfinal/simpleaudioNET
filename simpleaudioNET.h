#pragma once

#pragma managed(push,off)
#include <simpleaudio.h>
#pragma managed(pop)

#include "iteratorNET.h"

using namespace System;

namespace simpleaudioNET {
	ref class Interface;
	ref class Device;
	ref class Session;

	public ref class Interface
	{
	public:
		Interface();
		~Interface();
		!Interface();
		Device ^getDefaultDevice();
		iteratorNET::Iterator<Device ^> ^deviceIterator();

	private:
		simpleaudio::Interface *pInterface;
	};

	public ref class Device
	{
	public:
		Device(simpleaudio::Device *pDevice);
		~Device();
		!Device();
		property float Volume
		{
			void set(float v);
			float get();
		}
		property String ^FriendlyName
		{
			String ^get();
		}
		iteratorNET::Iterator<Session ^> ^sessionIterator();

	private:
		simpleaudio::Device *pDevice;
	};

	public ref class Session
	{
	public:
		Session(simpleaudio::Session *pSession);
		~Session();
		!Session();
		property float Volume
		{
			void set(float v);
			float get();
		}
		property String ^ DisplayName
		{
			String ^get();
		}

	private:
		simpleaudio::Session *pSession;
	};

	/* Iterator Profiles */

	public ref class DeviceIteratorProfile : public iteratorNET::IIteratorProfile<Device ^>
	{
	public:
		DeviceIteratorProfile(simpleaudio::DeviceIteratorProfile *pItProf);
		~DeviceIteratorProfile();
		!DeviceIteratorProfile();
		virtual Device ^get(UInt32 index);
		virtual UInt32 count();

	private:
		simpleaudio::DeviceIteratorProfile *pItProf;
	};

	public ref class SessionIteratorProfile : public iteratorNET::IIteratorProfile<Session ^>
	{
	public:
		SessionIteratorProfile(simpleaudio::SessionIteratorProfile *pItProf);
		~SessionIteratorProfile();
		!SessionIteratorProfile();
		virtual Session ^get(UInt32 index);
		virtual UInt32 count();

	private:
		simpleaudio::SessionIteratorProfile *pItProf;
	};
}