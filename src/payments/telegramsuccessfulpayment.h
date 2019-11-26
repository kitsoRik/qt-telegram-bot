#ifndef TELEGRAMSUCCESSFULPAYMENT_H
#define TELEGRAMSUCCESSFULPAYMENT_H

#include <QJsonObject>

class TelegramOrderInfo;

class TelegramSuccessfulPayment
{
public:
	TelegramSuccessfulPayment(const QJsonObject &json);
	~TelegramSuccessfulPayment();

	/// Necessarily
	QString currency() const;
	/// Necessarily
	int totalAmount() const;
	/// Necessarily
	QString invoicePayload() const;
	/// Optional
	QString shippingOptionId() const;
	/// Optional
	TelegramOrderInfo *orderInfo() const;
	/// Necessarily
	QString telegramPaymentChargeId() const;
	/// Necessarily
	QString providerPaymentChargeId() const;

private:
	QString m_currency;
	int m_totalAmount;
	QString m_invoicePayload;
	QString m_shippingOptionId;
	TelegramOrderInfo *m_orderInfo;
	QString m_telegramPaymentChargeId;
	QString m_providerPaymentChargeId;
};

#endif // TELEGRAMSUCCESSFULPAYMENT_H
