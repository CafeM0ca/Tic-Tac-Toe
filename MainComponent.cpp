/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent() : turn(true), cnt(0)
{
	setSize (600, 400);
	gameStart();
	
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)

    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

void MainComponent::buttonClicked(Button* button)
{
	if (button->isOver())
	{
		if (turn) {
			button->setColour(TextButton::buttonColourId, Colours::red);
			button->setButtonText("O");
		}
		else {
			button->setColour(TextButton::buttonColourId, Colours::blue);
			button->setButtonText("X");
		}
		button->removeListener(this);											// doesn't click
		cnt++;																	// clicked button count plus
		turn = !turn;															// change player turn

		auto dw = std::make_unique<AlertWindow>("AlertWindow", "TTT Winner Message", AlertWindow::AlertIconType::InfoIcon);
		if (whoIsWin()) {
			if (!turn) {
				//AlertWindow aw("Winner", "1p win!", AlertWindow::NoIcon);
				std::cout << "1p win" << std::endl;
				dw->showMessageBoxAsync(AlertWindow::AlertIconType::InfoIcon, "1p win!!!", "congraturation");
			
			}
			else {
				//	AlertWindow aw("Winner", "2p win!", AlertWindow::NoIcon);
				std::cout << "2p win" << std::endl;
				dw->showMessageBoxAsync(AlertWindow::AlertIconType::InfoIcon, "2p win!!!", "congraturation");
			}
		}
		else if (cnt == 9) {
			dw->showMessageBoxAsync(AlertWindow::AlertIconType::InfoIcon, "Draw", "Retry!!");
		}

	}

}

void MainComponent::gameStart()
{
	int x = getWidth() / 3;
	int y = getHeight() / 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			btn[i][j] = std::make_unique<TextButton>();
			btn[i][j]->setColour(TextButton::buttonColourId, Colours::white);
			btn[i][j]->setBounds(i*x, j*y, x, y);
			btn[i][j]->setButtonText("click");
			btn[i][j]->addListener(this);
			addAndMakeVisible(*btn[i][j]);
		}
	}
}

bool MainComponent::whoIsWin()
{
	std::cout << "whoiswin" << std::endl;
	if (cnt >= 5) {
		for (int i = 0; i < 3; i++) {
			if (btn[i][0]->getButtonText() == btn[i][1]->getButtonText() &&
				btn[i][1]->getButtonText() == btn[i][2]->getButtonText() &&
				btn[i][0]->getButtonText() != "click") {
				return true;
			}
		}
		for (int i = 0; i < 3; i++) {
			if (btn[0][i]->getButtonText() == btn[1][i]->getButtonText() &&
				btn[1][i]->getButtonText() == btn[2][i]->getButtonText() &&
				btn[0][i]->getButtonText() != "click")
				return true;
		}

		if (btn[0][0]->getButtonText() == btn[1][1]->getButtonText() &&
			btn[1][1]->getButtonText() == btn[2][2]->getButtonText() &&
			btn[0][0]->getButtonText() != "click")
			return true;
		else if (btn[0][2]->getButtonText() == btn[1][1]->getButtonText() &&
			btn[1][1]->getButtonText() == btn[2][0]->getButtonText() &&
			btn[0][2]->getButtonText() != "click")
			return true;
	}
	else {
		return false;
	}
}