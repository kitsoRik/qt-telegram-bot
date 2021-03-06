#ifndef TELEGRAMINLINEKEYBOARDMARKUP_H
#define TELEGRAMINLINEKEYBOARDMARKUP_H

#include "telegraminlinekeyboardbutton.h"
#include <QList>
#include "itelegrammessagekeyboard.h"
#include "telegrambasetypes.h"


class TelegramInlineKeyboardMarkup : public TelegramBaseTypes, public iTelegramMessageKeyboard
{
public:
	TelegramInlineKeyboardMarkup(const QJsonObject &json);
	TelegramInlineKeyboardMarkup(const QList<TelegramInlineKeyboardButton> &keyboard);

	QList<TelegramInlineKeyboardButton> inlineKeyboard() const;
	void setInlineKeyboard(const QList<TelegramInlineKeyboardButton> &inlineKeyboard);

	QJsonObject toJson() const override;

private:
	QList<TelegramInlineKeyboardButton> m_inlineKeyboard;
};

#endif // TELEGRAMINLINEKEYBOARDMARKUP_H
