#include "stdafx.h"

#include "simpleaudioNET.h"

/* Interface */
simpleaudioNET::Interface::Interface()
{
	this->pInterface = new simpleaudio::Interface();
}

simpleaudioNET::Interface::~Interface()
{
	this->!Interface();
}

simpleaudioNET::Interface::!Interface()
{
	delete pInterface;
}

simpleaudioNET::Device ^ simpleaudioNET::Interface::getDefaultDevice()
{
	simpleaudio::Device *pNativeDevice;
	pInterface->getDefaultDevice(&pNativeDevice);
	return gcnew Device(pNativeDevice);
}

iteratorNET::Iterator<simpleaudioNET::Device ^> ^ simpleaudioNET::Interface::deviceIterator()
{
	simpleaudio::DeviceIteratorProfile *pNativeItProf;
	pNativeItProf = new simpleaudio::DeviceIteratorProfile(pInterface);
	DeviceIteratorProfile ^pItProf = gcnew DeviceIteratorProfile(pNativeItProf);
	return gcnew iteratorNET::Iterator<Device ^>(pItProf);
}

/* Device */
simpleaudioNET::Device::Device(simpleaudio::Device *pDevice)
{
	this->pDevice = pDevice;
}

simpleaudioNET::Device::~Device()
{
	this->!Device();
}

simpleaudioNET::Device::!Device()
{
	delete pDevice;
}

void simpleaudioNET::Device::Volume::set(float v)
{
	pDevice->setVolume(v);
}

float simpleaudioNET::Device::Volume::get()
{
	return pDevice->getVolume();
}

String ^simpleaudioNET::Device::FriendlyName::get()
{
	const int len = 200;
	wchar_t friendlyName[len];
	pDevice->getFriendlyName(friendlyName, len);
	return gcnew String(friendlyName);
}

iteratorNET::Iterator<simpleaudioNET::Session ^> ^simpleaudioNET::Device::sessionIterator()
{
	simpleaudio::SessionIteratorProfile *pNativeItProf;
	pNativeItProf = new simpleaudio::SessionIteratorProfile(pDevice);
	SessionIteratorProfile ^pItProf = gcnew SessionIteratorProfile(pNativeItProf);
	return gcnew iteratorNET::Iterator<Session ^>(pItProf);
}

/* Session */
simpleaudioNET::Session::Session(simpleaudio::Session *pSession)
{
	this->pSession = pSession;
}

simpleaudioNET::Session::~Session()
{
	this->!Session();
}

simpleaudioNET::Session::!Session()
{
	delete pSession;
}

void simpleaudioNET::Session::Volume::set(float v)
{
	pSession->setVolume(v);
}

float simpleaudioNET::Session::Volume::get()
{
	return pSession->getVolume();
}

String ^simpleaudioNET::Session::DisplayName::get()
{
	const int len = 200;
	wchar_t displayName[len];
	pSession->getDisplayName(displayName, len);
	return gcnew String(displayName);
}

/* DeviceIteratorProfile */

simpleaudioNET::DeviceIteratorProfile::DeviceIteratorProfile(simpleaudio::DeviceIteratorProfile *pItProf)
{
	this->pItProf = pItProf;
}

simpleaudioNET::DeviceIteratorProfile::~DeviceIteratorProfile()
{
	this->!DeviceIteratorProfile();
}

simpleaudioNET::DeviceIteratorProfile::!DeviceIteratorProfile()
{
	delete pItProf;
}

simpleaudioNET::Device ^simpleaudioNET::DeviceIteratorProfile::get(UInt32 index)
{
	simpleaudio::Device *pDevice;
	pItProf->get(index, &pDevice);
	return gcnew Device(pDevice);
}

UInt32 simpleaudioNET::DeviceIteratorProfile::count()
{
	return pItProf->count();
}

/* SessionIteratorProfile */
simpleaudioNET::SessionIteratorProfile::SessionIteratorProfile(simpleaudio::SessionIteratorProfile *pItProf)
{
	this->pItProf = pItProf;
}

simpleaudioNET::SessionIteratorProfile::~SessionIteratorProfile()
{
	this->!SessionIteratorProfile();
}

simpleaudioNET::SessionIteratorProfile::!SessionIteratorProfile()
{
	delete pItProf;
}

simpleaudioNET::Session ^simpleaudioNET::SessionIteratorProfile::get(UInt32 index)
{
	simpleaudio::Session *pSession;
	pItProf->get(index, &pSession);
	return gcnew Session(pSession);
}

UInt32 simpleaudioNET::SessionIteratorProfile::count()
{
	return pItProf->count();
}