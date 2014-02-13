#ifndef FURROVINEUSB_H
#define FURROVINEUSB_H
#ifdef FURROVINEOPENGL

#include <Furrovine++/Core.h>

namespace Furrovine {
	
	class USB {
	private:
		static libusb_device** devices;
		static int count;
		static int lastcount;
		
	public:
		static int Change ( ) {
			Poll();
			return count - lastcount;
		}

		static int Poll () {
			lastcount = count;
			if (devices != null)
				libusb_free_device_list(devices, 1);
			count = libusb_get_device_list(null, &devices);
			return count;
		}

		static void Quit () {
			libusb_free_device_list(devices, 1);
			libusb_exit(NULL);
		}
	};

#ifdef FURROVINECOMPILE
	int USB::lastcount = 0;
	int USB::count = 0;
	libusb_device** USB::devices = null;
#endif // FURROVINECOMPILE 

}

#endif // FURROVINEOPENGL 
#endif // FURROVINEUSB_H 