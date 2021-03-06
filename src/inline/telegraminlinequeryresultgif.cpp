#include "telegraminlinequeryresultgif.h"


TelegramInlineQueryResultGif::
TelegramInlineQueryResultGif(const QString &id,
							 const QString &gifUrl,
							 const QString &thumbUrl,
							 const int &gifWidth,
							 const int &gifHeight,
							 const int &gifDuration,
							 const QString &title,
							 const QString &caption,
							 const QString &parseMode,
							 const TelegramInlineKeyboardMarkup replyMarkup,
							 const TelegramInputMessageContent *inputMessageContent)
	: m_id(id),
	  m_gifUrl(gifUrl),
	  m_thumbUrl(thumbUrl),
	  m_gifWidth(gifWidth),
	  m_gifHeight(gifHeight),
	  m_gifDuration(gifDuration),
	  m_title(title),
	  m_caption(caption),
	  m_parseMode(parseMode),
	  m_replyMarkup(replyMarkup),
	  m_inputMessageContent(inputMessageContent == nullptr ? nullptr : inputMessageContent->clone())

{

}

TelegramInlineQueryResultGif::
TelegramInlineQueryResultGif(const TelegramInlineQueryResultGif &result)
	:  m_id(result.m_id),
	  m_gifUrl(result.m_gifUrl),
	  m_thumbUrl(result.m_thumbUrl),
	  m_gifWidth(result.m_gifWidth),
	  m_gifHeight(result.m_gifHeight),
	  m_gifDuration(result.m_gifDuration),
	  m_title(result.m_title),
	  m_caption(result.m_caption),
	  m_parseMode(result.m_parseMode),
	  m_replyMarkup(result.m_replyMarkup),
	  m_inputMessageContent(result.m_inputMessageContent == nullptr ?
								nullptr : result.m_inputMessageContent->clone())
{ }

TelegramInlineQueryResultGif::~TelegramInlineQueryResultGif()
{
	delete m_inputMessageContent;
}

QJsonObject TelegramInlineQueryResultGif::toJson() const
{
	QJsonObject json;

	json["type"] = "gif";
	json["id"] = m_id;
	json["gif_url"] = m_gifUrl;
	json["thumb_url"] = m_thumbUrl;
	if(m_gifWidth > -1) json["gif_width"] = m_gifWidth;
	if(m_gifHeight > -1) json["gif_height"] = m_gifHeight;
	if(m_gifDuration > -1) json["gif_duration"] = m_gifDuration;
	if(!m_title.isEmpty()) json["title"] = m_title;
	if(!m_caption.isEmpty()) json["caption"] = m_caption;
	if(!m_parseMode.isEmpty()) json["parse_mode"] = m_parseMode;
	if(m_replyMarkup.isNotNull()) json["reply_markup"] = m_replyMarkup.toJson();
	if(m_inputMessageContent) json["input_message_content"] = m_inputMessageContent->toJson();

	return json;
}
