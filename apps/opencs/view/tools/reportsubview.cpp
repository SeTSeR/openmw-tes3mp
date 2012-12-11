
#include "reportsubview.hpp"

#include <QTableView>
#include <QHeaderView>

#include "../../model/tools/reportmodel.hpp"

CSVTools::ReportSubView::ReportSubView (const CSMWorld::UniversalId& id, CSMDoc::Document& document)
: CSVDoc::SubView (id)
{
    setWidget (mTable = new QTableView (this));
    mTable->setModel (document.getReport (id));

    mTable->horizontalHeader()->setResizeMode (QHeaderView::Interactive);
    mTable->verticalHeader()->hide();
    mTable->setSortingEnabled (true);
    mTable->setSelectionBehavior (QAbstractItemView::SelectRows);
    mTable->setSelectionMode (QAbstractItemView::ExtendedSelection);
}

void CSVTools::ReportSubView::setEditLock (bool locked)
{
    // ignored. We don't change document state anyway.
}