/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Component/MasterMeter.h"

//==============================================================================
/**
*/
class SimpleGuitarAmpSimAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SimpleGuitarAmpSimAudioProcessorEditor (SimpleGuitarAmpSimAudioProcessor&);
    ~SimpleGuitarAmpSimAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SimpleGuitarAmpSimAudioProcessor& audioProcessor;
    Gui::MasterMeter masterMeterL, masterMeterR;

    ScopedPointer<Slider> driveKnob;
    ScopedPointer<Slider> rangeKnob;
    ScopedPointer<Slider> blendKnob;
    ScopedPointer<Slider> volumeKnob;

    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> driveAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> rangeAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> blendAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> volumeAttachment;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleGuitarAmpSimAudioProcessorEditor)
};
