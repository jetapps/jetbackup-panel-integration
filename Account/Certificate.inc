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

interface Certificate {

	/**
	 * provides the panel id.
	 * the the panel id needs to be as follow 'namespace_name'.
	 * e.g. 'MyCompany_PanelName'.
	 *
	 * @return string represents the panel.
	 */
	public function getPanel(): string;

	/**
	 * provides the domain of the certificate.
	 *
	 * @return string the certificate domain.
	 */
	public function getDomain(): string;

	/**
	 * provides the private key of the certificate.
	 *
	 * @return string the certificate private key.
	 */
	public function getPrivateKey(): string;

	/**
	 * provides the certificate as string.
	 *
	 * @return string the certificate.
	 */
	public function getCertificate(): string;

	/**
	 * provides a chain of certificate authority certificates.
	 *
	 * @return string a chain of CA certificates.
	 */
	public function getCAChain(): string;

	/**
	 * provides the custom data of the certificate (optional, can returns an empty string).
	 * it includes any information that the panel needs for the certificate.
	 * its an internal data of the panel, it can receives whatever the panel needs,
	 * the data will be backed up and restored as is.
	 *
	 * @return string the custom data of the certificate.
	 */
	public function getCustomData(): string;

	/**
	 * removes the certificate.
	 *
	 * @return void
	 * @throws PanelException throws if there is an issue with removing the certificate.
	 */
	public function remove();
}