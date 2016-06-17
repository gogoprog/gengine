#include "script.h"

#include <Urho3D/Scene/Component.h>
#include <Urho3D/Audio/Sound.h>
#include <Urho3D/Audio/SoundSource.h>
#include <Urho3D/Audio/Audio.h>
#include <Urho3D/Core/Context.h>

using namespace Urho3D;

EMBINDCEFV8_DECLARE_CLASS(Audio);
EMBINDCEFV8_DECLARE_CLASS(Context);
EMBINDCEFV8_DECLARE_CLASS(Component);
EMBINDCEFV8_DECLARE_STRING(String, CString);

EMBINDCEFV8_BINDINGS(audio)
{
    embindcefv8::Class<Audio>("Audio")
        .method("setMasterGain", &Audio::SetMasterGain)
        ;

    embindcefv8::Class<Sound>("Sound")
        ;

    embindcefv8::Class<SoundSource, Component>("SoundSource")
        .constructor<Context*>()
        .method("play", static_cast<void (SoundSource::*)(Sound*)>(&SoundSource::Play))
        .method("play2", static_cast<void (SoundSource::*)(Sound*, float, float, float)>(&SoundSource::Play))
        .method("stop", &SoundSource::Stop)
        .method("setSoundType", &SoundSource::SetSoundType)
        .method("setFrequency", &SoundSource::SetFrequency)
        .method("setGain", &SoundSource::SetGain)
        .method("setAttenuation", &SoundSource::SetAttenuation)
        .method("setPanning", &SoundSource::SetPanning)
        .method("isPlaying", &SoundSource::IsPlaying)
        ;
}
