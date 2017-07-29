#include "bindings.h"

#include <Urho3D/Scene/Component.h>
#include <Urho3D/Audio/Sound.h>
#include <Urho3D/Audio/SoundSource.h>
#include <Urho3D/Audio/Audio.h>
#include <Urho3D/Core/Context.h>

using namespace Urho3D;

EMBINDCEFV8_DECLARE_CLASS(Audio, void);
EMBINDCEFV8_DECLARE_CLASS(Context, void);
EMBINDCEFV8_DECLARE_STRING(String, CString);

EMBINDCEFV8_BINDINGS(audio)
{
    embindcefv8::Class<Audio>("Audio")
        .method("setMasterGain", &Audio::SetMasterGain)
        ;

    embindcefv8::Class<Sound>("Sound")
        .method("setLooped", &Sound::SetLooped)
        ;

}
