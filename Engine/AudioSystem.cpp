#include "AudioSystem.h" 
#include <fmod.hpp> 
#include "Logger.h"

namespace neu
{
	void AudioSystem::Initialize()
	{
		FMOD::System_Create(&m_fmodSystem);

		void* extradriverdata = nullptr;
		m_fmodSystem->init(32, FMOD_INIT_NORMAL, extradriverdata);
	}

	void AudioSystem::Shutdown()
	{
		for (auto& sound : m_sounds)
		{
			sound.second->release();
		}
		m_sounds.clear();
		m_fmodSystem->close();
		m_fmodSystem->release();
	}

	void AudioSystem::Update()
	{
		m_fmodSystem->update();
	}

	void AudioSystem::AddAudio(const std::string& name, const std::string& filename)
	{
		if (m_sounds.find(name) == m_sounds.end()) 
		{
			FMOD::Sound* sound = nullptr;
			m_fmodSystem->createSound(filename.c_str(), FMOD_DEFAULT, 0, &sound);
			m_sounds[name] = sound;
		}
	}

	void AudioSystem::PlayAudio(const std::string& name,bool loop)
	{
		auto iter = m_sounds.find(name);
			if (iter != m_sounds.end())
			{

				FMOD::Sound* sound = iter->second;
				if(loop) sound->setMode(FMOD_LOOP_NORMAL);
				else sound->setMode(FMOD_LOOP_OFF);

				FMOD::Channel* channel;
				m_fmodSystem->playSound(sound, 0, false, &channel);
			}

	}
	AudioChannel AudioSystem::PlayAudio(const std::string& name, float volume, float pitch, bool loop)
	{
		// find sound in map 
		auto iter = m_sounds.find(name);
		// if sound key not found in map (iter == end()), return default channel 
		if (iter == m_sounds.end())
		{
			LOG("Error could not find sound %s.", name.c_str());
			return AudioChannel{};
		}

		// get sound pointer from iterator 
		FMOD::Sound* sound = iter->second;
		FMOD_MODE mode = (loop) ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF;
		sound->setMode(mode);

		// play sound, sets the pointer to the channel it is playing in 
		FMOD::Channel* channel;
		m_fmodSystem->playSound(sound, 0, false, &channel);
		channel->setVolume(volume);
		channel->setPitch(pitch);
		channel->setPaused(false);

		// return audio channel with channel pointer set 
		return AudioChannel{ channel };
	}

}