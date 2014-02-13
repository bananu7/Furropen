#ifndef FURROVINEUSBDEVICE_H
#define FURROVINEUSBDEVICE_H

namespace Furrovine {
	
	class USBDevice {
	private:
		//libusb_device* usbdevice;
		
	public:
		
		USBDevice (int deviceindex) {
			//usbdevice = USB::DeviceAt( deviceindex );
		}
	
		~USBDevice () {
			//usbdevice = null;
		}
	};
	
}

#endif // FURROVINEUSBDEVICE_H 