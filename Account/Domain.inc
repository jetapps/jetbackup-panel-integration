<?php
/*
*
* JetBackup @ package
* Created By Idan Ben-Ezra
*
* Copyrights @ JetApps
* https://www.jetapps.com
*
**/
namespace JetBackup\Core\Panel\Integration\Account;

use JetBackup\Core\Exception\PanelException;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

interface Domain {

	/**
	 * the type of the main domain.
	 * the domain that you have chosen to represent your website address,
	 * there is only one main domain per account.
	 * @var int
	 */
	const TYPE_MAIN_DOMAIN  = 1;
	/**
	 * an addon domain type.
	 * an addon domain is a fully functional domain that can be created from within the control panel.
	 * this addon domain is a new, unique website hosted in a new folder on your account so that
	 * you can host several domains from one control panel.
	 * @var int
	 */
	const TYPE_ADDON_DOMAIN = 2;
	/**
	 * a sub domain type.
	 * a subdomain is a subset of an existing larger domain (main/addon domain).
	 * @var int
	 */
	const TYPE_SUBDOMAIN    = 3;
	/**
	 * an alias domain type.
	 * a domain that points to another existing domain (main/addon/sub domain).
	 * @var int
	 */
	const TYPE_ALIAS        = 4;

	/**
	 * provides the panel id.
	 * the the panel id needs to be as follow 'namespace_name'.
	 * e.g. 'MyCompany_PanelName'.
	 *
	 * @return string represents the panel.
	 */
	public function getPanel(): string;

	/**
	 * provides the name of the domain.
	 *
	 * @return string the domain name.
	 */
	public function getName(): string;

	/**
	 * provides the public directory of the domain.
	 *
	 * @return string the public directory of the domain.
	 */
	public function getPublicDir(): string;

	/**
	 * provides the type of the domain.
	 *
	 * @return int the domain type (see @uses for available domain types).
	 *
	 * @uses \JetBackup\Core\Panel\Integration\Account\Domain::TYPE_MAIN_DOMAIN main domain type.
	 * @uses \JetBackup\Core\Panel\Integration\Account\Domain::TYPE_ADDON_DOMAIN addon domain type.
	 * @uses \JetBackup\Core\Panel\Integration\Account\Domain::TYPE_SUBDOMAIN sub domain type.
	 * @uses \JetBackup\Core\Panel\Integration\Account\Domain::TYPE_ALIAS alias domain type.
	 */
	public function getType(): int;

	/**
	 * provides the parent domain of the domain.
	 *
	 * @return Domain the parent domain of this domain.
	 * @throws PanelException
	 */
	public function getParent():? Domain;

	/**
	 * provides the path to the zone file of the domain.
	 *
	 * @return string the path to the zone file of the domain.
	 */
	public function getZoneFile():? string;

	/**
	 * provides the custom data of the domain (optional, can returns an empty string).
	 * it includes any information that the panel needs for the domain.
	 * its an internal data of the panel, it can receives whatever the panel needs,
	 * the data will be backed up and restored as is.
	 *
	 * @return string the custom data of the domain.
	 */
	public function getCustomData(): string;

	/**
	 * removes the domain.
	 * it receives a boolean parameter that indicates whether you want to remove the domain data or not.
	 *
	 * @param bool $remove_data indicate if you want to remove the domain data or not.
	 *
	 * @return void
	 * @throws PanelException throws if there is an issue with removing the domain.
	 */
	public function remove($remove_data=false);
}