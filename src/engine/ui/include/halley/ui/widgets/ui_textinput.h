#pragma once

#include "../ui_widget.h"
#include "halley/core/graphics/sprite/sprite.h"
#include "halley/core/graphics/text/text_renderer.h"
#include "halley/core/input/input_device.h"
#include "halley/text/i18n.h"

namespace Halley {
	class UIStyle;

	class UITextInput : public UIWidget {
	public:
		explicit UITextInput(std::shared_ptr<InputDevice> keyboard, String id, UIStyle style, String text = "", LocalisedString ghostText = LocalisedString());
		bool canInteractWithMouse() const override;

		UITextInput& setText(const String& text);
		String getText() const;
		UITextInput& setGhostText(const LocalisedString& text);
		LocalisedString getGhostText() const;

		Maybe<int> getMaxLength() const;
		void setMaxLength(Maybe<int> length);

		void onManualControlActivate() override;

	protected:
		void draw(UIPainter& painter) const override;
		void update(Time t, bool moved) override;

		void onFocus() override;
		void pressMouse(Vector2f mousePos, int button) override;

		void readFromDataBind() override;

	private:
		void updateTextInput();
		void setCaretPosition(int pos);

		std::shared_ptr<InputDevice> keyboard;
		UIStyle style;
		Sprite sprite;
		Sprite caret;
		TextRenderer label;

		StringUTF32 text;
		LocalisedString ghostText;

		Maybe<int> maxLength;

		int caretPos = 0;
		float caretPhysicalPos = 0;
		float caretTime = 0;
		bool caretShowing = false;
	};
}
