#include <Furrovine++/std_defines.h>
#include <vector>
#include <array>
#include <Furrovine++/Vector2.h>
#include <Furrovine++/Input/Key.h>

namespace Furrovine { namespace Input {

	struct KeyboardState {
	private:
		furrovineapi static std::vector<KeyboardState> keyboardstates;
		int32 deviceid;
		bool connected;
		std::array<bool, 256> keystates;

	public:
		furrovineapi static const KeyboardState Dead;

		furrovineapi KeyboardState (  );

		furrovineapi int32 DeviceId ();

		furrovineapi bool Connected ();

		furrovineapi bool Down ( Key key );

		furrovineapi bool Up ( Key key );

		furrovineapi void Reset ();

		furrovineapi bool IsDead ();

		furrovineapi bool& operator[] ( Key key );

		furrovineapi const bool& operator[] ( Key key ) const;

		furrovineapi bool& operator[] ( ulword index );

		furrovineapi const bool& operator[] ( ulword index ) const;

		furrovineapi ~KeyboardState ();

		furrovineapi static void ManipulateState ( Key key, bool state, int32 deviceid = 0 );

		furrovineapi static const KeyboardState& GetState ( int32 deviceid = 0 );
	};

}}
