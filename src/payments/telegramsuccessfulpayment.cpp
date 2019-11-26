#include "telegramsuccessfulpayment.h"
#include "telegramorderinfo.h"

TelegramSuccessfulPayment::TelegramSuccessfulPayment(const QJsonObject &json)
{
	m_currency = json["currency"].toString("");
	m_totalAmount = json["total_amount"].toInt(-1);
	m_invoicePayload = json["invoice_payload"].toString("");
	m_shippingOptionId = json["shipping_option_id"].toString("");
	m_orderInfo = (json.contains("order_info")) ? new TelegramOrderInfo(json["order_info"].toObject()) : nullptr;
	m_telegramPaymentChargeId = json["telegram_payment_charge_id"].toString("");
	m_providerPaymentChargeId = json["provider_payment_charge_id"].toString("");
}

TelegramSuccessfulPayment::~TelegramSuccessfulPayment()
{
	if(m_orderInfo)
		delete m_orderInfo;
}

QString TelegramSuccessfulPayment::currency() const
{
    return m_currency;
}

int TelegramSuccessfulPayment::totalAmount() const
{
    return m_totalAmount;
}

QString TelegramSuccessfulPayment::invoicePayload() const
{
    return m_invoicePayload;
}

QString TelegramSuccessfulPayment::shippingOptionId() const
{
    return m_shippingOptionId;
}

TelegramOrderInfo *TelegramSuccessfulPayment::orderInfo() const
{
    return m_orderInfo;
}

QString TelegramSuccessfulPayment::telegramPaymentChargeId() const
{
    return m_telegramPaymentChargeId;
}

QString TelegramSuccessfulPayment::providerPaymentChargeId() const
{
    return m_providerPaymentChargeId;
}
