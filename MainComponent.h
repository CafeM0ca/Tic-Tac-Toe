/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component, private Button::Listener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //=============================================================j=================
    void paint (Graphics&) override;
    void resized() override;
	void buttonClicked(Button* button) override;
	//void paintButton(Graphics &g, bool isMouseOverButton, bool isButtonDown) override;
private:
    //==============================================================================
    // Your private member variables go here...

	std::unique_ptr<TextButton> btn[3][3];
	bool turn;
	int cnt;
	bool whoIsWin();
	void gameStart();
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
	