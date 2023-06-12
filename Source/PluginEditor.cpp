/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SimpleGuitarAmpSimAudioProcessorEditor::SimpleGuitarAmpSimAudioProcessorEditor(SimpleGuitarAmpSimAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p),
    masterMeterL([&]() {return audioProcessor.getRmsValue(0); }),
    masterMeterR([&](){ return audioProcessor.getRmsValue(0); })
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    addAndMakeVisible(masterMeterL);
    addAndMakeVisible(masterMeterR);
    
    addAndMakeVisible(driveKnob = new Slider("Drive"));
    driveKnob->setSliderStyle(Slider::Rotary);
    driveKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
    
    addAndMakeVisible(rangeKnob = new Slider("Range"));
    rangeKnob->setSliderStyle(Slider::Rotary);
    rangeKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

    addAndMakeVisible(blendKnob = new Slider("Blend"));
    blendKnob->setSliderStyle(Slider::Rotary);
    blendKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

    addAndMakeVisible(volumeKnob = new Slider("Volume"));
    volumeKnob->setSliderStyle(Slider::Rotary);
    volumeKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

    driveAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "drive", *driveKnob);
    rangeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "range", *rangeKnob);
    blendAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "blend", *blendKnob);
    volumeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "volume", *volumeKnob);

    setSize (500, 500);
}

SimpleGuitarAmpSimAudioProcessorEditor::~SimpleGuitarAmpSimAudioProcessorEditor()
{
}

//==============================================================================
void SimpleGuitarAmpSimAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::darkgrey);
    g.setFont (15.0f);

    g.drawText("Drive", ((getWidth() / 5) * 1) - (100 / 2), (getHeight() / 2) + 5, 100, 100, Justification::centred, false);
    g.drawText("Range", ((getWidth() / 5) * 2) - (100 / 2), (getHeight() / 2) + 5, 100, 100, Justification::centred, false);
    g.drawText("Blend", ((getWidth() / 5) * 3) - (100 / 2), (getHeight() / 2) + 5, 100, 100, Justification::centred, false);
    g.drawText("Volume", ((getWidth() / 5) * 4) - (100 / 2), (getHeight() / 2) + 5, 100, 100, Justification::centred, false);

    
}

void SimpleGuitarAmpSimAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    masterMeterL.setBounds(450, 200, 15, 200);
    masterMeterR.setBounds(475, 200, 15, 200);

    driveKnob->setBounds(((getWidth() / 5) * 1) - (100 / 2), (getHeight() / 2) - (100 / 2), 100, 100);
    rangeKnob->setBounds(((getWidth() / 5) * 2) - (100 / 2), (getHeight() / 2) - (100 / 2), 100, 100);
    blendKnob->setBounds(((getWidth() / 5) * 3) - (100 / 2), (getHeight() / 2) - (100 / 2), 100, 100);
    volumeKnob->setBounds(((getWidth() / 5) * 4) - (100 / 2), (getHeight() / 2) - (100 / 2), 100, 100);
}
