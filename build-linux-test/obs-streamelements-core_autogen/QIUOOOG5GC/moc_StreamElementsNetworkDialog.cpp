/****************************************************************************
** Meta object code from reading C++ file 'StreamElementsNetworkDialog.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../streamelements/StreamElementsNetworkDialog.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StreamElementsNetworkDialog.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN27StreamElementsNetworkDialogE_t {};
} // unnamed namespace

template <> constexpr inline auto StreamElementsNetworkDialog::qt_create_metaobjectdata<qt_meta_tag_ZN27StreamElementsNetworkDialogE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "StreamElementsNetworkDialog",
        "reject",
        "",
        "DownloadFileAsyncUpdateUserInterface",
        "dltotal",
        "dlnow",
        "UploadFileAsyncUpdateUserInterface",
        "on_ctl_cancelButton_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'reject'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'DownloadFileAsyncUpdateUserInterface'
        QtMocHelpers::SlotData<void(long, long)>(3, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Long, 4 }, { QMetaType::Long, 5 },
        }}),
        // Slot 'UploadFileAsyncUpdateUserInterface'
        QtMocHelpers::SlotData<void(long, long)>(6, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Long, 4 }, { QMetaType::Long, 5 },
        }}),
        // Slot 'on_ctl_cancelButton_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<StreamElementsNetworkDialog, qt_meta_tag_ZN27StreamElementsNetworkDialogE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject StreamElementsNetworkDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN27StreamElementsNetworkDialogE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN27StreamElementsNetworkDialogE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN27StreamElementsNetworkDialogE_t>.metaTypes,
    nullptr
} };

void StreamElementsNetworkDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<StreamElementsNetworkDialog *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->reject(); break;
        case 1: _t->DownloadFileAsyncUpdateUserInterface((*reinterpret_cast<std::add_pointer_t<long>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<long>>(_a[2]))); break;
        case 2: _t->UploadFileAsyncUpdateUserInterface((*reinterpret_cast<std::add_pointer_t<long>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<long>>(_a[2]))); break;
        case 3: _t->on_ctl_cancelButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *StreamElementsNetworkDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StreamElementsNetworkDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN27StreamElementsNetworkDialogE_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int StreamElementsNetworkDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
