/******************************************************************************
 * QSkinny - Copyright (C) 2016 Uwe Rathmann
 * This file may be used under the terms of the QSkinny License, Version 1.0
 *****************************************************************************/

#ifndef QSK_SCROLL_AREA_H
#define QSK_SCROLL_AREA_H

#include "QskScrollView.h"

class QSK_EXPORT QskScrollArea : public QskScrollView
{
    Q_OBJECT

    Q_PROPERTY( QQuickItem* scrolledItem READ scrolledItem
        WRITE setScrolledItem NOTIFY scrolledItemChanged FINAL)

    Q_PROPERTY( bool itemResizable READ isItemResizable
        WRITE setItemResizable NOTIFY itemResizableChanged FINAL )

    Q_PROPERTY( bool autoScrollFocusedItem READ autoScrollFocusItem
        WRITE setAutoScrollFocusedItem NOTIFY autoScrollFocusedItemChanged FINAL )

    using Inherited = QskScrollView;

  public:
    QskScrollArea( QQuickItem* parent = nullptr );
    ~QskScrollArea() override;

    void setScrolledItem( QQuickItem* );
    QQuickItem* scrolledItem() const;

    void setItemResizable( bool on );
    bool isItemResizable() const;

    void setAutoScrollFocusedItem( bool on );
    bool autoScrollFocusItem() const;

    void ensureItemVisible( const QQuickItem* );

  Q_SIGNALS:
    void itemResizableChanged();
    void scrolledItemChanged();
    void autoScrollFocusedItemChanged();

  protected:
    void updateLayout() override;

  private:
    void translateItem();
    void adjustItem();

    class PrivateData;
    std::unique_ptr< PrivateData > m_data;
};

#endif
