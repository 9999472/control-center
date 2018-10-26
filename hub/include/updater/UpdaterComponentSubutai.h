#ifndef UPDATERCOMPONENTSUBUTAI_H
#define UPDATERCOMPONENTSUBUTAI_H

#include "updater/IUpdaterComponent.h"

namespace update_system {

  /**
   * @brief The CUpdaterComponentSubutai class implements IUpdaterComponent. Works with Subutai
   */
  class CUpdaterComponentSubutai : public IUpdaterComponent {
  private:
    static QString subutai_path();
    static QString download_subutai_path();

  protected:
    virtual bool update_available_internal();
    virtual chue_t update_internal();
    virtual void update_post_action(bool success);
    virtual chue_t install_internal();
    virtual void install_post_internal(bool success);
    virtual chue_t uninstall_internal();
    virtual void uninstall_post_internal(bool success);

  public:
    CUpdaterComponentSubutai();
    virtual ~CUpdaterComponentSubutai();
  };
}

#endif // UPDATERCOMPONENTSUBUTAI_H
