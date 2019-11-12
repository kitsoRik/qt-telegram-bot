#ifndef TELEGRAMFILE_H
#define TELEGRAMFILE_H

#include <QJsonObject>

class TelegramFile
{
public:
	TelegramFile(const QJsonObject &json);

	QString fileId() const;
	int fileSize() const;
	QString filePath() const;

private:
	QString m_fileId;
	int m_fileSize;
	QString m_filePath;
};

#endif // TELEGRAMFILE_H