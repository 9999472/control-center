#include <QApplication>
#include "updater/HubComponentsUpdater.h"
#include "updater/UpdaterComponentSubutai.h"
#include "SystemCallWrapper.h"
#include "NotificationObserver.h"
#include "OsBranchConsts.h"
#include "Commons.h"

using namespace update_system;


////////////////////////////////////////////////////////////////////////////

CUpdaterComponentSubutai::CUpdaterComponentSubutai() {
  m_component_id = SUBUTAI;
}

CUpdaterComponentSubutai::~CUpdaterComponentSubutai() {

}
////////////////////////////////////////////////////////////////////////////

bool
CUpdaterComponentSubutai::update_available_internal() {
  return false;
}
////////////////////////////////////////////////////////////////////////////

chue_t
CUpdaterComponentSubutai::update_internal() {
  this->update_progress_sl(0, 50);
  static QString empty_string = "";

  SilentUpdater *silent_updater = new SilentUpdater(this);
  silent_updater->init(empty_string, empty_string, CC_SUBUTAI);

  connect(silent_updater, &SilentUpdater::outputReceived, this,
          &CUpdaterComponentSubutai::update_finished_sl);

  silent_updater->startWork();

  return CHUE_SUCCESS;
}
////////////////////////////////////////////////////////////////////////////

void
CUpdaterComponentSubutai::update_post_action(bool success) {
  if (!success) {
    CNotificationObserver::Error(tr("Failed to update the Subutai. Make sure that you have the required permissions."), DlgNotification::N_SETTINGS);
  } else {
    CNotificationObserver::Error(tr("Successfully updated the Subutai."), DlgNotification::N_NO_ACTION);
  }
}
////////////////////////////////////////////////////////////////////////////

QString
CUpdaterComponentSubutai::subutai_path() {
  return QApplication::applicationFilePath();
}
////////////////////////////////////////////////////////////////////////////

QString
CUpdaterComponentSubutai::download_subutai_path() {
    QStringList lst_temp = QStandardPaths::standardLocations(QStandardPaths::TempLocation);
    return (lst_temp.isEmpty() ? QApplication::applicationDirPath() : lst_temp[0]) +
                                QDir::separator() + SUBUTAI;
}

////////////////////////////////////////////////////////////////////////////
//instalation stuff just to make compiler happy
chue_t CUpdaterComponentSubutai::install_internal(){
    return CHUE_SUCCESS;
}

void CUpdaterComponentSubutai::install_post_internal(bool success) {
  UNUSED_ARG(success);
  return;
}

chue_t CUpdaterComponentSubutai::uninstall_internal() {
  m_in_progress = false;
  return CHUE_SUCCESS;
}

void CUpdaterComponentSubutai::uninstall_post_internal(bool success) {
  UNUSED_ARG(success);
}
