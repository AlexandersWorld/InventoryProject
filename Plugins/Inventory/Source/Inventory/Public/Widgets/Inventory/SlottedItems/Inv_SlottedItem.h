// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inv_SlottedItem.generated.h"

class UInv_InventoryItem;
class UImage;
class UTextBlock;

UCLASS()
class INVENTORY_API UInv_SlottedItem : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	UImage* GetImageIcon() const { return Image_Icon; }
	int32 GetGridIndex() const { return GridIndex; }
	FIntPoint GetGridDimensions() const { return GridDimensions; }
	bool IsStackable() const { return bIsStackable; }
	UInv_InventoryItem* GetInventoryItem() const { return InventoryItem.Get(); }
	
	void SetGridIndex(int32 Index) { GridIndex = Index; }
	void SetIsStackable(bool bStackable) { bIsStackable = bStackable; }
	void SetGridDimensions(const FIntPoint& Dimensions) { GridDimensions = Dimensions; }
	void SetInventoryItem(UInv_InventoryItem* Item);
	void SetImageBrush(const FSlateBrush& Brush) const;
	void UpdateStackCount(int32 StackCount);
private:
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> Image_Icon;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> Text_StackCount;
	
	int32 GridIndex;
	FIntPoint GridDimensions;
	TWeakObjectPtr<UInv_InventoryItem> InventoryItem;
	bool bIsStackable {false};
	
};
