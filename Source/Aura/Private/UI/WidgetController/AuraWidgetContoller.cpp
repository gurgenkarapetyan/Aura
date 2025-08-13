// Copyright Gurgen Karapetyan


#include "UI/WidgetController/AuraWidgetContoller.h"

void UAuraWidgetContoller::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}
